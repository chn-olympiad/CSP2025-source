#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=505,mod=998244353;
int n,m,ret,sum,c[N],b[N],jc[N]; 
bool vis[N];
string s;
void dfs(int x){
	if(x==n+1)
	{
		int sum=0,num=0;
		for(int i=1;i<=n;i++)
		{
			if(s[i-1]=='0')sum++;
			else 
			{
				if(sum>=c[b[i]])sum++;
				else num++;
			}
		}
		if(num>=m)
		{
			ret++;
			if(ret>=mod)ret-=mod;
		}
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(vis[i]==1)continue;
		vis[i]=1;
		b[x]=i;
		dfs(x+1);
		vis[i]=0;
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>s;
	jc[0]=1;
	for(int i=1;i<N;i++)jc[i]=jc[i-1]*i%mod;
	for(int i=1;i<=n;i++)cin>>c[i],sum+=(c[i]==0);
	if(n<=10)
	{
		dfs(1);
		cout<<ret;
		return 0;
	}
	if(m==1&&s[0]=='0')cout<<0; 
	else cout<<jc[n-1]*sum%mod;
	return 0;
}

