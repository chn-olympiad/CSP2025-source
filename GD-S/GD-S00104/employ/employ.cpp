#include<bits/stdc++.h>
#define ll long long
#define R register
#define PII pair<int,int>
#define count(x) __builtin_popcount(x)
#define mk(x,y) make_pair(x,y)
using namespace std;
const int mod=998244353,N=505;
int n,m,c[N+1],all;string s;
ll f[1<<18][19];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m>>s;s=" "+s;
	for(R int i=1;i<=n;++i)cin>>c[i];
	if(n==m){
		for(R int i=1;i<=n;++i)if(c[i]==0)return cout<<0,0;
		for(R int i=1;i<=n;++i)if(s[i]=='0')return cout<<0,0;
		ll mul=1;
		for(R int i=1;i<=n;++i)mul=mul*i%mod;
		cout<<mul;
		return 0;
	}
	all=(1<<n)-1;
	f[0][0]=1;
	for(R int i=1;i<=all;++i){
		for(R int j=0;j<n;++j)if((i&(1<<j))){
			int to=count(i^(1<<j));
			for(R int k=0;k<n;++k){
				if(s[to+1]=='0'||c[j+1]<=k){
					f[i][k+1]=(f[i][k+1]+f[i^(1<<j)][k])%mod;
				}else f[i][k]=(f[i][k]+f[i^(1<<j)][k])%mod;
			}
		}
	}
	ll del=n-m,sum=0;
	for(R int i=0;i<=del;++i)sum=(sum+f[all][i])%mod;
	cout<<sum;
	return 0;
}