#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll cnt[110],f[20][20];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ll n,m,x,a;
	int k=0;
	cin>>n>>m;
	cin>>x;
	cnt[x]++;
	for(ll i=2;i<=n*m;i++){
		cin>>a;
		cnt[a]++;
	}
	for(ll i=100;i>=0;i--){
		if(cnt[i]){
			k++;
			if(i==x){
				break;
			}
		}
	}
	f[1][1]=1;
	for(ll i=2;i<=m;i++){
		if(i%2==0){
			f[1][i]=n*2-1+f[1][i-1];
		}else f[1][i]=f[1][i-1]+1;
	}
	for(ll i=2;i<=n;i++){
		for(ll j=1;j<=m;j++){
			if(j%2==0)f[i][j]=f[i-1][j]-1;
			else f[i][j]=f[i-1][j]+1;
		}
	}
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=m;j++){
			if(f[i][j]==k){
				cout<<j<<" "<<i;
				return 0;
			}
		}
	}
	
	return 0;
}
