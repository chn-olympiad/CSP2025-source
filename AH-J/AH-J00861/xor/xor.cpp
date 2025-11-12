#include<bits/stdc++.h>
using namespace std;
int n,a[50005],k,c;
vector<int> l,r;
bool f(int i,int j){
	int s=0;
	for(int l=i;l<=j;l++){
		s=(s xor a[l]);
	}return s==k;
}
bool d(int l,int r,int L,int R){
	if(R>r){
		if(L>r) return 0;
		else return 1; 
	}else{
		if(l>R) return 0;
		else return 1;
	}
}
bool e(int a,int b){
	int q=l.size();
	for(int i=0;i<q;i++){
		if(d(a,b,l[i],r[i])){
			return 0;
		}
	}return 1;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=0;i<n;i++){
		for(int j=1;j<=n;j++){
			if(j+i>n){
				continue;
			}
			if(f(j,j+i)){
				if(e(j,j+i)){
					c++;
					l.push_back(j);r.push_back(j+i);
				}
			}
		}
	}cout<<c;
	return 0;
}
