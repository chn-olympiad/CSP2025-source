#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN=505;
const ll mod=998244353;
int n,m,c[MAXN],len[MAXN];
bool vis[MAXN];
ll sum;
string S;
void dfs(int x) 
{ 
	if(x>n) 
	{ 
		int num=0,ans=0;
		for(int i=1;i<=n;++i) 
		{ 
			if(S[i-1]=='0'||S[i-1]=='1'&&num<c[len[i]]) ++num;
			else ++ans;
		} 
		if(ans>=m) ++sum,sum%=mod;
		return ;
	} 
	for(int i=1;i<=n;++i) 
		if(!vis[i]) vis[i]=true,len[x]=i,dfs(x+1),vis[i]=false;
} 
int main() 
{ 
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n>>m>>S;
	for(int i=1;i<=n;++i) 
		cin>>c[i];
	if(n<=13) 
	{ 
		dfs(1);
		cout<<sum;
		return 0;
	} 

	return 0;
} 
