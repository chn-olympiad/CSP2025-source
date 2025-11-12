#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+1;
ll T;
ll n;
ll a[N][4];
ll b[4][N],b1[4];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		ll ans=0;
		for(int i=1;i<=3;i++)b1[i]=0;
		for(int i=1;i<=3;i++){
			for(int j=1;j<=N;j++){
				b[i][j]=0;
			}
		}
		for(ll i=1;i<=n;i++){
			ll maxn=0;
			for(ll j=1;j<=3;j++){
				cin>>a[i][j];
				maxn=max(maxn,a[i][j]);
			}
			for(ll j=1;j<=3;j++){
				if(a[i][j]==maxn){
					b[j][i]=1;
					b1[j]++;
					break;
				}
			}
		}
		for(ll i=1;i<=3;i++){
			if(b1[i]<=n/2)continue;
			while(b1[i]>n/2){
				ll cnt=2e4,x,y;
				for(ll j=1;j<=n;j++){
					if(b[i][j]==0)continue;
					for(ll k=1;k<=3;k++){
						if(i==k||b1[k]>n/2)continue;
						ll num=a[j][i]-a[j][k];
						if(num<=cnt){
							cnt=num;
							x=k,y=j;
						}
			
					}
				}
				b[i][y]=0;
				b[x][y]=1;
				b1[i]--;
				b1[x]++;
			}
		}
		for(ll i=1;i<=3;i++){
			for(ll j=1;j<=n;j++){
				if(b[i][j])ans+=a[j][i];
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
