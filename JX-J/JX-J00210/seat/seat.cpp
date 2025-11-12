#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1005],k,l,c;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	//freopen("seat.in","r",stdin);
	//freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	k=a[0];
	sort(a,a+n*m,cmp);
	for(int i=0;i<n*m;i++){
		if(a[i]==k){
			k=i;
		}
	}
	k++;
	for(int i=0;;i++){
		if(k>n*2){
			k-=n*2;
			l++;
		}
		else break;
	}
	if(k>n){
		cout<<l*2+2<<" ";
		cout<<2*n+1-k;
		return 0;
	}else{
		cout<<l*2+1<<" ";
		cout<<k;
	}
	return 0;
}
