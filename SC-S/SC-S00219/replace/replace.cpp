//神秘哈希男子，骗30pts
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define lll __int128
#define md 998244353
#define bs 29
const int mxn=2e3+114;
int n,Q;
unordered_map<int,vector<int> > e[mxn];
int pw[mxn];
struct AutoHashMaton
{
	int hs[mxn];
	inline void init(string s)
	{
		memset(hs,0,sizeof(hs));
		int f=s.length(); s=" "+s;
		for (int i=1;i<=f;i++) hs[i]=(hs[i-1]*bs+s[i]-'a')%md;
	}
	inline int gths(int l,int r)
	{
		return (((hs[r]-(hs[l-1]*pw[r-l+1])%md)+md)%md);
	}
}nw1,nw2,tmp;
struct node
{
	int rigin,tob;
}T[mxn];
inline void init()
{
	pw[0]=1;
	for (int i=1;i<mxn;i++) pw[i]=(pw[i-1]*bs)%md;
}
inline int mergehs(int lenr,int hsl,int hsr)
{
	return (hsr+hsl*pw[lenr])%md;
}
string s,sp;
signed main()
{
	cin.tie(0)->sync_with_stdio(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>Q;
	init();
	for (int i=1;i<=n;i++)
	{
		cin>>s>>sp; tmp.init(s); T[i].rigin=tmp.gths(1,s.length()); 
		tmp.init(sp); T[i].tob=tmp.gths(1,s.length());
		e[s.length()][T[i].rigin].emplace_back(T[i].tob);
	}
	while (Q--)
	{
		cin>>s>>sp;
		nw1.init(s); nw2.init(sp);	
		int ans=0;
		int len=s.length();
		for (int i=0;i<=len;i++)//左分割端点 hsl=nw1.gths(1,i)
		{
			for (int l=0;i+l<=len;l++)//lenr=l
			{
				if (e[l].find(nw1.gths(i+1,i+l))==e[l].end()) continue;
				for (auto val:e[l][nw1.gths(i+1,i+l)])
				{
					if (mergehs(len-i-l,mergehs(l,nw1.gths(1,i),val),nw1.gths(i+l+1,len))==nw2.gths(1,len)) ans++;
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}