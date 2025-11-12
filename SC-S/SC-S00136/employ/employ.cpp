#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=510,mod=998244353;
int n,m,c[N];
char s[N];

namespace BF{
	int vis[15],ans=0;
	void dfs(int step,int sum){
		if(step==n+1){
			if(sum>=m) ans++;
			return ;
		}
		if(sum+n-step+1<m) return ;
		for(int i=1;i<=n;i++){
			if(!vis[i]){
				vis[i]=1;
				int nsum=sum;
				if(s[step]=='1'&&c[i]>step-1-sum) nsum++;
				dfs(step+1,nsum);
				vis[i]=0;
			}
		}
	}
	void solve(){
		dfs(1,0);
		cout<<ans<<endl;
	}
}

signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>s[i];
	for(int i=1;i<=n;i++) cin>>c[i];
	if(n<=18){
		BF::solve(); return 0;
	}
	if(m==n){
		for(int i=1;i<=n;i++)
			if(s[i]=='0'){cout<<0<<endl; return 0;}
		for(int i=1;i<=n;i++)
			if(c[i]=='0'){cout<<0<<endl; return 0;}
	}
	int mul=1;
	for(int i=1;i<=n;i++) mul=mul*i%mod;
	cout<<mul<<endl;
	return 0;
}