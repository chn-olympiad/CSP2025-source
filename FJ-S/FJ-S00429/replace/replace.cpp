#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	int x=0;char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar());
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<3)+(x<<1)+(ch^48);
	return x;
}
inline void Read(vector<char> &s)
{
	s.emplace_back(' ');
	char ch=getchar();
	for(;ch<'a'||ch>'z';ch=getchar());
	for(;ch>='a'&&ch<='z';ch=getchar()) s.emplace_back(ch);
}
const int N=2e5+5,M=5e6+5,BASE=13331,mod=998244353,mod2=1e9+7;
int n,Q,f[M];
vector<char> s[N][2],t[2];
vector<int> a[N],b,nxt[N];
map<int,int> mp,mp2;
void trans(vector<int> &a,vector<char> s1,vector<char> s2)
{
	a.emplace_back(0);
	for(int i=1;i<(int)s1.size();i++) a.emplace_back((s1[i]-'a')*26+s2[i]-'a');
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	n=read();Q=read();
	for(int i=1;i<=n;i++)
	{
		Read(s[i][0]),Read(s[i][1]),trans(a[i],s[i][0],s[i][1]);
//		int hsh=0,hsh2=0;
//		for(int j=1;j<(int)s[i][0].size();j++) hsh=((1ll*hsh*BASE)%mod+a[i][j]+1)%mod;
//		for(int j=1;j<(int)s[i][0].size();j++) hsh2=((1ll*hsh2*BASE)%mod2+a[i][j]+1)%mod2;
//		if(mp[hsh]&&mp[hsh2]&&mp[hsh]==mp[hsh2]) s[i][0].clear(),s[i][1].clear(),a[i].clear(),i--,n--;
//		else mp[hsh]=mp[hsh2]=i;
	}
	for(int k=1;k<=n;k++)
	{
		int siz=s[k][0].size();
		nxt[k].resize(siz);
		for(int i=2;i<siz;i++)
		{
			int j=nxt[k][i-1];
			for(;j&&a[k][j+1]!=a[k][i];j=nxt[k][j]);
			if(a[k][j+1]==a[k][i]) j++;
			nxt[k][i]=j;
		}
	}
	for(;Q--;)
	{
		Read(t[0]);Read(t[1]);trans(b,t[0],t[1]);
		int siz=t[0].size(),L=siz,R=0;
		for(int i=1;i<siz;i++)
			if(t[0][i]!=t[1][i]) L=min(L,i),R=i;
		long long res=0;
		for(int k=1;k<=n;k++)
			for(int i=1;i<siz;i++)
			{
				int j=f[i-1];
				if(j+1==(int)a[k].size()) j--;
				for(;j&&a[k][j+1]!=b[i];j=nxt[k][j]);
				if(a[k][j+1]==b[i]) j++;
				f[i]=j;
				if(j+1==(int)s[k][0].size()) res+=i>=R&&i-j+1<=L;
			}
		printf("%lld\n",res);
		t[0].clear();t[1].clear();b.clear();
	}
	return 0;
}
