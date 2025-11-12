#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
namespace yyh{
	int n,m,ans;
	string s;
	int a[505],p[505];
	bool v[505];
	void dfs(int x){
		if(x>n){
			int cnt=0,o=0;
			for(int i=1;i<=n;i++){
				if(s[i-1]=='1'&&o<a[p[i]])cnt++;
				else o++;
			}
			if(cnt>=m)ans++;
			return;
		}
		for(int i=1;i<=n;i++)
			if(!v[i]){
				v[i]=1;
				p[x]=i;
				dfs(x+1);
				v[i]=0;
			}
	}
	int sum=0,c[505][505];
	ll jx[505];
	signed main(){
		cin>>n>>m>>s;
		for(int i=0;i<s.size();i++)
			sum+=s[i]-'0';
		int o=0;
		for(int i=1;i<=n;i++)
			cin>>a[i],o+=(a[i]==0);
		dfs(1);
		if(sum==n){
			c[0][0]=1;
			for(int i=1;i<=n;i++){
				c[i][0]=1;
				for(int j=1;j<=i;j++)
					c[i][j]=(c[i-1][j]+c[i-1][j-1])%998244353;
			}
			if(n-o<m)cout<<0<<endl;
			else{
				ll ans=c[n-o][m];
				jx[0]=1;
				for(int i=1;i<=n;i++)jx[i]=jx[i-1]*i%998244353;
				cout<<(ans*jx[m]%998244353*jx[n-m])%998244353;
			}
			return 0;
		}
		cout<<ans<<endl;
		return 0;
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	yyh::main();
	return 0;
}
/*
10 5
1101111011
6 0 4 2 1 2 5 4 3 3
*/
