#include<bits/stdc++.h>
using namespace std;
int n,k,sum;
int a[500010];
bool b[1000000010];
bool pd(int x,int y){
	for(int i=x;i<=y;i++){
		if(b[i]){
			return 0;
		}
	}
	if(x==y){
		if(a[x]==k){
			b[x]=true;
			return 1;
		}else{
			return 0;
		}
	}
	int m=a[x]^a[x+1];
	for(int i=x+2;i<=y;i++){
		m^=a[i];
	}
	if(m==k){
		for(int i=x;i<=y;i++){
			b[i]=true;
		}
		return 1;
	}
	return 0;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(pd(i,j)){
				sum++;
			}
		}
	}
	cout<<sum;
	return 0;
}
