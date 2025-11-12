#include<bits/stdc++.h>
#define int long long
#define fore(x,m,n) for(int x=m;x<=n;x++)
using namespace std;

const int maxn=5e6+5;
int n,q;
string s1,s2;
int ch[maxn][26];
int ed[maxn],id=1,cnt=0;
map<int,vector<string> > m;
int dep;

void insert(string s1,string s2)
{
	int len=s1.size(),p=1;
	fore(i,0,len-1)
	{
		int j=s1[i]-'a';
		if(!ch[p][j]) ch[p][j]=++id;
		p=ch[p][j];
	}
	if(!ed[p]) ed[p]=++cnt;
	m[cnt].push_back(s2);
}
int query(string s)
{
	int len=s.size(),p=1;
	fore(i,0,len-1)
	{
		int j=s[i]-'a';
		if(ed[p]) return ed[p];
		if(!ch[p][j]) return -1;
		p=ch[p][j];
		dep++;
	}
	return ed[p];
}

signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>q;
	fore(i,1,n)
	{
		cin>>s1>>s2;
		insert(s1,s2);
	}
	fore(i,1,q)
	{
		cin>>s1>>s2;
		int ans=0;
		fore(j,0,s1.size()-1)
		{
			string s=s1.substr(j);
			dep=0;
			int k=query(s);
			if(k==-1)
			{
				continue;
			}
			for(string q:m[k])
			{
				string tmp=s1.substr(0,j);
				tmp+=q;
				tmp+=s1.substr(j+dep);
				if(tmp==s2) ans++;
			}
			
		}
		cout<<ans<<'\n';
	}
	return 0;
}
