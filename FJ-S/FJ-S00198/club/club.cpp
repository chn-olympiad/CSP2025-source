#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=210;
const ll M=1e5+10;
ll Q,n,a[N][4],dp[N][N][N],ans,b[M];
inline ll read(){
	ll x=0,f=1;
	char ch=getchar();
	while(ch<'0' || ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0' && ch<='9'){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
bool cmp(ll x,ll y){
	return x>y;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	Q=read();
	while(Q--){
		n=read();
		for(ll i=1;i<=n;i++){
			a[i][1]=read();
			a[i][2]=read();
			a[i][3]=read();
		}
		if(n<=200){
			memset(dp,0,sizeof(dp));
			for(ll i=0;i<=n/2;i++){
				for(ll j=0;j<=n/2;j++){
					for(ll k=0;k<=n/2 && i+j+k<=n;k++){
						if(i+j+k==0) continue;
						if(i>0) dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k]+a[i+j+k][1]);
						if(j>0) dp[i][j][k]=max(dp[i][j][k],dp[i][j-1][k]+a[i+j+k][2]);
						if(k>0) dp[i][j][k]=max(dp[i][j][k],dp[i][j][k-1]+a[i+j+k][3]);
					}
				}
			}
			ans=0;
			for(ll i=1;i<=n/2;i++){
				for(ll j=1;j<=n/2;j++){
					ll k=n-i-j;
					if(k>n/2) continue;
					ans=max(ans,dp[i][j][k]);
				}
			}
			cout<<ans<<'\n';
		}
		else{
			ans=0;
			for(ll i=1;i<=n;i++) b[i]=a[i][1];
			sort(b+1,b+n+1,cmp);
			for(ll i=1;i<=n/2;i++) ans+=b[i];
			cout<<ans<<'\n';
		}
	}
	return 0;
}
