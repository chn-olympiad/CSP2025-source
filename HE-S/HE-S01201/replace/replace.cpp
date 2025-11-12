#include<bits/stdc++.h>
#define pi pair<int,int>
#define fi first
#define se second
#define mk make_pair
using namespace std;
const int N=2e5+5,M=5e6+5,md=1e9+7,base=13331;
int n,q,fa[M],siz[M],cnt,tr[M][27],pos;
string s[N],s1[N],t[N],t1[N];
void clear()
{
	for(int i=0;i<=cnt;i++)
	{
		fa[i]=siz[i]=0;
		for(int j=0;j<27;j++)
			tr[i][j]=0;
	}
	cnt=0;
}
void getfail()
{
	queue<int> q;
	for(int i=0;i<27;i++)
		if(tr[0][i]) q.push(tr[0][i]);
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		siz[u]+=siz[fa[u]];
		for(int i=0;i<27;i++)
		{
			if(tr[u][i]) fa[tr[u][i]]=tr[fa[u]][i],q.push(tr[u][i]);
			else tr[u][i]=tr[fa[u]][i];
		}
	}
}
vector<int> b[N];
vector<int> c[N];
map<pi,int> mp;
int ans[N],L[N],R[N],L1[N],R1[N];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i]>>s1[i];
		int m=s[i].size();
		while(L[i]<m&&s[i][L[i]]==s1[i][L[i]]) L[i]++;
		while(R[i]<m&&s[i][m-R[i]-1]==s1[i][m-R[i]-1]) R[i]++;
		int v=0,v1=0;
		for(int j=L[i];j<m-R[i];j++)
		{
			v=(1ll*v*base+s[i][j])%md;
			v1=(1ll*v1*base+s1[i][j])%md;
		}
	//	cout<<L[i]<<' '<<R[i]<<' '<<v<<' '<<v1<<endl;
		if(!mp[mk(v,v1)])
			mp[mk(v,v1)]=++pos;
		b[mp[mk(v,v1)]].push_back(i);
	}
//	cout<<"OK"<<endl;
	for(int i=1;i<=q;i++)
	{
		cin>>t[i]>>t1[i];
		if(t[i].size()!=t1[i].size()) continue;
		int m=t[i].size();
		while(L1[i]<m&&t[i][L1[i]]==t1[i][L1[i]]) L1[i]++;
		if(L1[i]==m) continue;
		while(R1[i]<m&&t[i][m-R1[i]-1]==t1[i][m-R1[i]-1]) R1[i]++;
		int v=0,v1=0;
		for(int j=L1[i];j<m-R1[i];j++)
		{
			v=(1ll*v*base+t[i][j])%md;
			v1=(1ll*v1*base+t1[i][j])%md;
		}
//		cout<<L1[i]<<' '<<R1[i]<<' '<<v<<' '<<v1<<endl;
		if(mp.find(mk(v,v1))==mp.end()) continue;
		c[mp[mk(v,v1)]].push_back(i);
	}
//	cerr<<pos<<endl;
//	cout<<"OK"<<endl;
	for(int x=1;x<=pos;x++)
	{
	//	if(x%100==0) cerr<<x<<endl;
		clear();
		for(int v:b[x]){
			int u=0;
			for(int i=0;i<L[v];i++)
			{
				int v1=s[v][i]-'a';
				if(!tr[u][v1]) tr[u][v1]=++cnt;
				u=tr[u][v1];
			}
			if(!tr[u][26]) tr[u][26]=++cnt;
			u=tr[u][26];
			for(int i=s[v].size()-R[v];i<s[v].size();i++)
			{
				int v1=s[v][i]-'a';
				if(!tr[u][v1]) tr[u][v1]=++cnt;
				u=tr[u][v1];
			}
			siz[u]++;
		}
		getfail();
		for(int v:c[x])
		{
			int u=0,res=0;
			for(int i=0;i<L1[v];i++)
			{
				int v1=t[v][i]-'a';
				u=tr[u][v1],res+=siz[u];
			}
			u=tr[u][26],res+=siz[u];
			for(int i=t[v].size()-R1[v];i<t[v].size();i++)
			{
				int v1=t[v][i]-'a';
				u=tr[u][v1],res+=siz[u];
			}
			ans[v]=res;
		}
	}
	for(int i=1;i<=q;i++) cout<<ans[i]<<'\n';
}
