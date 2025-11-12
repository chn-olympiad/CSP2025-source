#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=1e9+7;
const int p=13;
const int N=2e5+5;
const int L=5e6+5;
int n,q,pn[L],son[L][30],cnt;
vector<int>ed[L];
vector<int>sub[N][2],s[2];
string s1[N],s2[N];
string t1,t2;
map<pair<int,int>,int>mp;
unordered_map<int,bool>mp1;
int ha(vector<int>sub,int l,int r)
{
	if(l>r)return 0;
	return (sub[r]-sub[l-1]*pn[r-l+1]%mod+mod)%mod;
}
void insert(int p,int i,int pre,int v)
{
	for(int o=pre;o>=1;o--)
	{
		int v=s1[i][o-1]-'a';
		if(!son[p][v])son[p][v]=++cnt;
		p=son[p][v];
	}
	ed[p].push_back(v);
}
int find(int p,int pre)
{
	int ans=0;
	for(int to:ed[p])if(mp1[to])ans++;
	for(int o=pre;o>=1;o--)
	{
		int v=t1[o-1]-'a';
		if(!son[p][v])return ans;
		p=son[p][v];
		for(int to:ed[p])if(mp1[to])ans++;
	}
	return ans;
}
signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>q;pn[0]=1;s[0].resize(L+1),s[1].resize(L+1);
	for(int i=1;i<L;i++)pn[i]=pn[i-1]*p%mod;
	for(int i=1;i<=n;i++)
	{
		sub[i][0].push_back(0);
		sub[i][1].push_back(0);
		cin>>s1[i]>>s2[i];
		int len=s1[i].size();
		int pre=0,last=len+1;
		for(int j=len;j>=1;j--)
		{
			if(s1[i][j-1]!=s2[i][j-1])break;
			last=j;
		}
		for(int j=1;j<=len;j++)
		{
			sub[i][0].push_back((sub[i][0].back()*p%mod+(s1[i][j-1]-'a'))%mod);
			sub[i][1].push_back((sub[i][1].back()*p%mod+(s2[i][j-1]-'a'))%mod);
			if(sub[i][0]==sub[i][1])pre=j;
		}
		int &x=mp[{ha(sub[i][0],pre+1,last-1),ha(sub[i][1],pre+1,last-1)}];
		if(!x)x=++cnt;
		insert(x,i,pre,ha(sub[i][0],last,len));
	}
	while(q--)
	{
		cin>>t1>>t2;
		int len1=t1.size(),len2=t2.size(),pre=0,last=len1+1;
		if(len1!=len2){cout<<"0\n";continue;}
		for(int i=len1;i>=1;i--)
		{
			if(t1[i-1]!=t2[i-1])break;
			last=i;
		}
		for(int i=1;i<=len1;i++)
		{
			s[0][i]=((s[0][i-1]*p)%mod+(t1[i-1]-'a'));
			s[1][i]=((s[1][i-1]*p)%mod+(t2[i-1]-'a'));
			if(s[0][i]==s[1][i])pre=i;
		}
		int x=mp[{ha(s[0],pre+1,last-1),ha(s[1],pre+1,last-1)}];
		if(!x){cout<<"0\n";continue;}
		mp1.clear(),mp1[0]=1;
		for(int i=last;i<=len1;i++)mp1[ha(s[0],last,i)]=1;
		cout<<find(x,pre)<<'\n';
	}
	return 0;
}
