#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=105,mod=998244353;
int n,m,num,a[N],b[N],id[N],s[N],dp[1<<19][20];
bool vis[N];
char c[N];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(c[i]=='1'){
			b[++num]=i;
			id[i]=num;
		}
		else{
			s[num+1]++;
		}
	}
	for(int i=1;i<=num+1;i++){
		s[i]+=s[i-1];
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(m==n){
		bool f=1;
		for(int i=1;i<=n;i++){
			if(c[i]=='0'||a[i]==0) f=0;
		}
		if(f==0) cout<<0;
		else{
			ll re=0;
			for(int i=1;i<=n;i++){
				re=re*i%mod;
			}
			cout<<re;
		}
		return 0;
	}
	dp[0][0]=1;
	for(int j=0;j<(1<<n);j++){
		int x=0;
		for(int i=1;i<=n;i++){
			x+=((j>>i-1)&1);
		}
		for(int i=0;i<=x;i++){
			for(int k=1;k<=n;k++){
				if(((j>>k-1)&1)==0){
					int tmp=(x-i<a[k])&(c[x+1]=='1');
					dp[j+(1<<k-1)][i+tmp]=(dp[j+(1<<k-1)][i+tmp]+dp[j][i])%mod;
				}
			}
		}
	}
	ll re=0;
	for(int i=m;i<=n;i++){
		re=(re+dp[(1<<n)-1][i])%mod;
	}
	cout<<re;
	return 0;
}
