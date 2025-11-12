#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define fi first
#define se second
#define pb push_back
#define pii pair<ll,ll>
#define ve vector<ll>
#define mid ((l+r)>>1)
#define lx (x<<1)
#define rx (x<<1|1)
using namespace std;
const ll N=502,P=998244353;
ll n,m,ans,d[N],fc[N],c[N][N],f[2][N][N];
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>s,s=" "+s;
	for(ll i=1,x;i<=n;i++)cin>>x,d[x]++;
	for(ll i=n;i>=0;i--)d[i]+=d[i+1];
	f[0][0][0]=1;
	for(ll i=0;i<=n;i++){
		fc[i]=(i?fc[i-1]*i:1)%P;
		for(ll j=0;j<=i;j++)
			c[i][j]=(j?c[i-1][j]+c[i-1][j-1]:1)%P;
	}
	for(ll i=1;i<=n;i++){
		memset(f[i&1],0,sizeof(f[i&1]));
		for(ll j=0;j<i;j++)
			for(ll k=0;k<=min(i-1,d[j+1]);k++){
				ll t=i&1,x=f[!t][j][k];
				if(!x)continue;
				if(k<d[j+1]){
					if(s[i]=='1')(f[t][j][k+1]+=x)%=P;
					else for(ll y=max(k+1-d[j+2],0ll);y<=min(d[j+1]-d[j+2],k+1);y++)
						(f[t][j+1][k+1-y]+=x*c[d[j+1]-d[j+2]][y]%P*c[k+1][y]%P*fc[y])%=P;
				}
				if(i-1-k<d[0]-d[j+1])
					for(ll y=max(k-d[j+2],0ll);y<=min(d[j+1]-d[j+2],k);y++)
						(f[t][j+1][k-y]+=x*(d[0]-d[j+1]-(i-1-k))%P*c[d[j+1]-d[j+2]][y]%P*c[k][y]%P*fc[y])%=P;
			}
	}
	for(ll i=0;i<=n-m;i++)(ans+=f[n&1][i][d[i+1]]*fc[d[i+1]])%=P;
	cout<<(ans+P)%P;
	return 0;
}
