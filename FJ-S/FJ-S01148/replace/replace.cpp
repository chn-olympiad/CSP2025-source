#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
const ull Base1=77563,Base2=99607;
map<ull,int> mp;
int tot;
int ttot;
map<char,int> son[11000005];
vector<int> v[11000005];
bool mk[10000005];
int dfn[11000005],R[11000005],dfntot;
int root1[1000005],root2[1000005];
int pos1[1000005],pos2[1000005];
ull hsh[1000005];
int tmp[1000005];
int n;
void insert(int x,string s,string t)
{
	int m=s.size();
	int l=0,r=m-1;
	while(s[l]==t[l]) l++;
	while(s[r]==t[r]) r--;
	for(int i=l;i<=r;i++) hsh[x]=hsh[x]*Base1+s[i];
	for(int i=l;i<=r;i++) hsh[x]=hsh[x]*Base2+t[i];
	if(mp[hsh[x]]) tmp[x]=mp[hsh[x]];
	else
	{
		if(x>n) return;
		tmp[x]=++tot,mp[hsh[x]]=tot;
		root1[tot]=++ttot;
		root2[tot]=++ttot;
	}
	pos1[x]=root1[tmp[x]];
	for(int i=l-1;i>=0;i--)
	{
		if(son[pos1[x]][s[i]]) pos1[x]=son[pos1[x]][s[i]];
		else son[pos1[x]][s[i]]=++ttot,v[pos1[x]].push_back(ttot),pos1[x]=ttot;
	}
	mk[pos1[x]]=true;
	pos2[x]=root2[tmp[x]];
	for(int i=r+1;i<m;i++)
	{
		if(son[pos2[x]][s[i]]) pos2[x]=son[pos2[x]][s[i]];
		else son[pos2[x]][s[i]]=++ttot,v[pos2[x]].push_back(ttot),pos2[x]=ttot;
	}
	mk[pos2[x]]=true;
//	if(pos2[x]==0) cout << "Hola" << endl;
}
int ans[1000005];
void dfs(int x)
{
	if(!mk[x])
	{
		for(int y:v[x]) dfs(y);
	}
	else
	{
		dfn[x]=++dfntot;
		for(int y:v[x]) dfs(y);
		R[x]=dfntot;
	}
}
int t[1000005];
void add(int x,int k)
{
	for(;x<=dfntot;x+=(x&-x)) t[x]+=k;
}
int ask(int x)
{
	int ans=0;
	for(;x;x-=(x&-x)) ans+=t[x];
	return ans;
}
vector<pair<pair<int,int>,int> > up[1000005];
vector<pair<int,int> > qry[1000005];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int Q;
	scanf("%d%d",&n,&Q);
	for(int i=1;i<=n;i++)
	{
		string s,t;
		cin >> s >> t;
		if(s==t) continue;
		insert(i,s,t);
	}
	for(int i=1;i<=Q;i++)
	{
		string s,t;
		cin >> s >> t;
//		if(i==462) cout << s << ' ' << t << endl;
		if(s.size()!=t.size()) continue;
		if(s==t) continue;
		insert(i+n,s,t);
	}
//	cout << "yeal" << endl;
//	for(int i=1;i<=n+Q;i++) cout << hsh[i] << ' ' << tmp[i] << endl;
	for(int i=1;i<=tot;i++)
	{
		dfs(root1[i]);
		dfs(root2[i]);
	}
//	cout << "yeal" << endl;
//	for(int i=1;i<=n+Q;i++) cout << dfn[pos1[i]] << ' ' << R[pos1[i]] << ' ' << dfn[pos2[i]] << ' ' << R[pos2[i]] << endl;
	for(int i=1;i<=n;i++) if(tmp[i])
	{
//		if(dfn[pos2[i]]==0) cout << i << ' ' << pos1[i] << ' ' << hsh[i] << endl;
		up[dfn[pos1[i]]].push_back(make_pair(make_pair(dfn[pos2[i]],R[pos2[i]]),1));
		up[R[pos1[i]]+1].push_back(make_pair(make_pair(dfn[pos2[i]],R[pos2[i]]),-1));
	}
//	cout << "yeal" << endl;
	for(int i=n+1;i<=n+Q;i++) if(dfn[pos1[i]])
	{
		qry[dfn[pos1[i]]].push_back(make_pair(i,dfn[pos2[i]]));
	}
	for(int i=1;i<=dfntot;i++)
	{
//		cout << i << endl;
		for(pair<pair<int,int>,int> p:up[i])
		{
//			cout << p.first.first << ' ' << p.first.second << ' ' << p.second << endl;
			add(p.first.first,p.second);
			add(p.first.second+1,-p.second);
		}
		for(pair<int,int> p:qry[i])
		{
//			cout << p.first << ' ' << p.second << endl;
			ans[p.first]=ask(p.second);
		}
	}
//	cout << "yeal" << endl;
//	cout << ans[462+n] << ' ' << hsh[462+n] << ' ' << tmp[462+n] << endl;
//	cout << dfntot << endl;
	for(int i=n+1;i<=n+Q;i++) printf("%d\n",ans[i]);
	return 0;
}
