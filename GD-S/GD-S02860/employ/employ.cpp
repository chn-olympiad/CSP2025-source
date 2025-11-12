#include <bits/stdc++.h>
#define int long long
using namespace std;
const int INF=0x7fffffff;
const int N=510;
const int M=1e3+10;
inline int read(){
	int a=0,f=1;
	char c=getchar();
	while(!isdigit(c)){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(isdigit(c)){
		a=a*10+c-'0';
		c=getchar();
	}
	return a*f;
}
int n,m,c[N],cnt;
int comps[M][N];
int p[N],vis[N];
int sum,ans;
string s;
void dfs(int dep){
	if(dep==n+1){
		cnt++;
		for(int i=1;i<=n;i++){
			comps[cnt][i]=p[i];
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			p[dep]=i;
			vis[i]=1;
			dfs(dep+1);
			vis[i]=0;
		}
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=read();
	m=read();
	cin>>s;
	s="%"+s;
	bool flag=1;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(s[i]=='0') flag=0;
	}
	if(flag){
		bool x=1;
		sum=0;
		memset(vis,0,sizeof(vis));
		while(x){
			x=0;
			for(int i=1;i<=n;i++){
				if(c[i]<=sum&&!vis[i]){
					vis[i]=1;
					sum++;
					x=1;
				}
			}
		}
		if(n-sum<m){
			cout<<0<<endl;
		}else{
			ans=1;
			for(int i=1;i<=n;i++){
				ans=(ans*i)%998244353;
			}
			cout<<ans<<endl;
		}
		return 0;
	}
	dfs(1);
	for(int x=1;x<=cnt;x++){
		sum=0;
		memset(vis,0,sizeof(vis));
		for(int i=1;i<=n;i++){
			if(s[i]=='0'&&!vis[comps[x][i]]||c[comps[x][i]]<=sum){
				vis[comps[x][i]]=1;
				sum++;
			}else vis[comps[x][i]]=-1;
		}
		if(n-sum>=m){
			ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}

