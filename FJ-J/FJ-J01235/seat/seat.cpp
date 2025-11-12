#include<bits/stdc++.h>
using namespace std;
int n,m;
int ans=0;
int pm=0;
int b[150],a[150];
int c[150];
int main(){
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>b[i];
		a[i]=b[i];
	}
	ans=b[1];
	if(b[1]==100){
		cout<<1<<" "<<1;
	}
	sort(b+1,b+n*m+1);
	for(int i=1;i<=n*m;i++){
		if(b[i]==ans){
			pm=n*m-i+1;
		}
	}
	for(int i=1;i<=n*m;i++){
		for(int j=1;j<=n*m;j++){
			if(pm==n or pm==n+i and pm<2*n){
				cout<<i<<" "<<n;
				break;
			}
			else if(pm==2*n){
				cout<<2<<" "<<1;
				break;
			}
			else if(pm==2*n+i){
				cout<<2+i<<" "<<1;
				break;
			}
		}
	}	
	return 0;
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
}
