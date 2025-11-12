#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define x first
#define y second
#define rep1(i,l,r) for(int i=l;i<=r;++i)
#define rep2(i,l,r) for(int i=l;i>=r;--i)
#define rep3(i,h,x,ne) for(int i=h[x];~i;i=ne[i])
#define rep4(x,v) for(auto x:v)
const int N=5e6+10;
const int inf=0x3f3f3f3f3f3f3f3f;
const int base=13;
const int mod=1e9+7;
using namespace std;
int n,q,h1[N],h2[N],pr[N];
map<pii,vector<int> > mp;
map<pii,int> mpp;
int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	n=read();
	q=read();
	bool res=1;
	rep1(i,1,n)
	{
		string s1,s2;
		cin>>s1>>s2;
		int len=s1.length()-1;
		int pos1=-1,pos2=-1,h1=0,h2=0;
		rep1(i,0,len) 
		{
			h1=(h1*base%mod+s1[i])%mod;
			if(s1[i]=='b') 
			{
				if(~pos1) res=0;
				pos1=i;
			}
		}
		rep1(i,0,len) 
		{
			h2=(h2*base%mod+s2[i])%mod;
			if(s2[i]=='b') 
			{
				if(~pos2) res=0;
				pos2=i;
			}
		}
		if(pos1==-1||pos2==-1) res=0;
		mp[make_pair(pos1-pos2,pos1)].push_back(len-pos2);
		++mpp[make_pair(h1,h2)];
	}
	pr[0]=1;
	rep1(i,1,100000) pr[i]=pr[i-1]*base%mod;
	while(q--)
	{
		string s1,s2;
		cin>>s1>>s2;
		if(s1.length()!=s2.length())
		{
			puts("0");
			continue;
		}
		int len=s1.length()-1;
		bool rea=1;
		int pos1=-1,pos2=-1;
		h1[0]=h2[0]=0;
		rep1(i,0,len) 
		{
			if(i) h1[i]=h1[i-1]*base%mod;
			h1[i]=(h1[i]+s1[i])%mod;
			if(s1[i]=='b') 
			{
				if(~pos1) rea=0;
				pos1=i;
			}
		}
		rep1(i,0,len) 
		{
			if(i) h2[i]=h2[i-1]*base%mod;
			h2[i]=(h2[i]+s2[i])%mod;
			if(s2[i]=='b') 
			{
				if(~pos2) rea=0;
				pos2=i;
			}
		}
		if(pos1==-1||pos2==-1) rea=0;
		if(rea&res)
		{
			int ans=0;
			rep1(i,0,pos1)
			{
				pii now=make_pair(pos1-pos2,i);
				sort(mp[now].begin(),mp[now].end());
				int id=upper_bound(mp[now].begin(),mp[now].end(),len-pos2)-mp[now].begin();
				ans+=id;
			}
			cout<<ans<<"\n";
			continue;
		}
		rep1(i,0,len)
		{
			if(s1[i]!=s2[i])
			{
				pos1=i;
				break;
			}
		}
		rep2(i,len,0)
		{
			if(s1[i]!=s2[i])
			{
				pos2=i;
				break;
			}
		}
		int ans=0;
		rep1(l,0,pos1)
		{
			rep1(r,pos2,len)
			{
				int H1=(h1[r]-(l?h1[l-1]:0)*pr[r-l+1]%mod+mod)%mod;
				int H2=(h2[r]-(l?h2[l-1]:0)*pr[r-l+1]%mod+mod)%mod;
				ans+=mpp[make_pair(H1,H2)];
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
/*
4 1
aba cbc
abab cbcb
dababa dcbcba
dababa dcbcbc
dababad dcbcbad

*/
