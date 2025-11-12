#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5,M=5e6+5;
typedef unsigned long long ull;
bool ST;
mt19937_64 rnd(114514);
int n,m,t[M][26],prt[M],cnt=1,dep[M],ans[N];
vector<ull>v[M];
unordered_map<ull,int>mp;
vector<int>e[M];
vector<pair<ull,int>>q[M];
ull H[26][26];
bool ED;
void insert(string s,ull hs)
{
	int x=1;
	for(auto cc:s)
	{
		int c=cc-'a';
		if(!t[x][c]) t[x][c]=++cnt,dep[cnt]=dep[x]+1;
		x=t[x][c];
	}
	v[x].push_back(hs);
}
void build()
{
	queue<int>q; q.push(1);
	while(!q.empty())
	{
		int x=q.front(); q.pop();
		for(int i=0;i<26;i++)
		{
			if(t[x][i])
			{
				int y=t[x][i],p=prt[x];
				while(p&&!t[p][i]) p=prt[p];
				prt[y]=p?t[p][i]:1,q.push(y);
			}
			else
			{
				int p=prt[x];
				while(p&&!t[p][i]) p=prt[p];
				t[x][i]=p?t[p][i]:1;
			}
		}
	}
}
void dfs(int x)
{
	for(auto it:v[x]) mp[it]++;
	for(auto it:q[x]) ans[it.second]+=mp[it.first];
	for(auto y:e[x]) dfs(y);
	for(auto it:v[x]) mp[it]--;
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cerr<<"mem: "<<(&ST-&ED)/1024.0/1024<<"\n";
	cin>>n>>m;
	for(int i=0;i<26;i++)
		for(int j=0;j<26;j++) H[i][j]=rnd();
	for(int i=1;i<=n;i++)
	{
		string s,t; cin>>s>>t;
		int len=s.size(); ull hs=0;
		for(int j=0;j<len;j++) if(s[j]!=t[j]) hs+=H[s[j]-'a'][t[j]-'a']*(len-j);
		insert(s,hs);
		// cerr<<"hs "<<i<<" "<<hs<<"\n";
	}
	build();
	for(int i=2;i<=cnt;i++) e[prt[i]].push_back(i);
	for(int i=1;i<=m;i++)
	{
		string a,b; cin>>a>>b;
		int len=a.size(),lst=-1; ull hs=0,sum=0;
		for(int j=0;j<len;j++) if(a[j]!=b[j]) lst=j;
		for(int j=0;j<len;j++)
			if(a[j]!=b[j]) hs+=H[a[j]-'a'][b[j]-'a']*(lst-j+1),sum+=H[a[j]-'a'][b[j]-'a'];
		int x=1;
		for(int j=0;j<len;j++)
		{
			x=t[x][a[j]-'a']; if(j<lst) continue;
			// cerr<<"?? "<<i<<" "<<j<<" | "<<x<<" "<<hs<<"\n";
			q[x].emplace_back(hs,i),hs+=sum;
		}
	}
	dfs(1);
	for(int i=1;i<=m;i++) cout<<ans[i]<<"\n";
	return 0;
}