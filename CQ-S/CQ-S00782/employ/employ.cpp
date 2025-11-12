#include<bits/stdc++.h>
#define ll long long 
using namespace std;
const int N=505,mod=998244353;
int n,m;
char S[N];
int c[N],v[N];
int f[19][1<<18|5],g[19][1<<18|5];
inline void _mod(int &x){if(x>=mod)x-=mod;}
int main(){ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>(S+1);
	for(int i=1;i<=n;i++)cin>>c[i],v[i]=v[i-1]+(S[i]=='1');
	if(m==n){int mn=n;
		for(int i=1;i<=n;i++)mn=min(mn,c[i]);
		if(!mn||v[n]!=n){
			cout<<0;
			return 0;
		}ll ans=1;
		for(int i=1;i<=n;i++)ans=ans*i%mod;
		cout<<ans;
		return 0;
	}
	sort(c+1,c+1+n);
	f[0][0]=1;
	for(int i=1;i<=n;i++){
		for(int j=0;j<i;j++)for(int s=0;s<1<<n;s++)g[j][s]=f[j][s],f[j][s]=0;
		for(int s=0;s<1<<n;s++){
			if(__builtin_popcount(s)!=i-1)continue;
			for(int j=0;j<i;j++){
				for(int k=1;k<=n;k++){
					if((1<<k-1)&s)continue;
					int nj=j+(S[i]=='0'||(j>=c[k]));
					f[nj][(1<<k-1)|s]+=g[j][s];
					_mod(f[nj][(1<<k-1)|s]);
				}
			}
		}
	}
	ll ans=0;
	for(int i=0;i<=n-m;i++){
		ans+=f[i][(1<<n)-1];
	}
	cout<<ans%mod;
	return 0;
}
