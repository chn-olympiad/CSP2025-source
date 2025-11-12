#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5,mod=998244353;
int n,q,hs[27],p[N],ans[N],h1[N],h2[N],pre1[N],pre2[N];
string s1[N],s2[N],t1[N],t2[N];
mt19937 rnd(time(0));
unordered_map<int,int> mp;

void solve1()
{
	for(int i=1;i<=n;i++)
	{
		cin>>s1[i]>>s2[i];
		bool flag=false;
		int base=1,res=0;
		for(int j=0;j<s1[i].size();j++)
		{
			if(s1[i][j]!=s2[i][j]) flag=true;
			if(flag) res=(res+(hs[s1[i][j]-'a']-hs[s2[i][j]-'a'])*base%mod)%mod,base=base*13%mod;
		}
		mp[res]++;
	}
	for(int i=1;i<=q;i++)
	{
		cin>>t1[i]>>t2[i];
		bool flag=false;
		int base=1,res=0;
		if(t1[i].size()!=t2[i].size())
		{
			cout<<"0\n";
			continue;
		}
		for(int j=0;j<t1[i].size();j++)
		{
			if(t1[i][j]!=t2[i][j]) flag=true;
			if(flag) res=(res+(hs[t1[i][j]-'a']-hs[t2[i][j]-'a'])*base%mod)%mod,base=base*13%mod;
		}
//		if(res==0) cout<<"0\n";
		cout<<mp[res]<<'\n';
	}
}

//void solve2()
//{
//	for(int i=1;i<=n;i++)
//	{
//		cin>>s1[i]>>s2[i];
//		int base=1;
//		for(int j=1;j<=s1[i].size();j++) h1[i]=(h1[i]+hs[s1[i][j-1]-'a']*base%mod)%mod,base=base*13%mod;
//		base=1;
//		for(int j=1;j<=s2[i].size();j++) h2[i]=(h2[i]+hs[s2[i][j-1]-'a']*base%mod)%mod,base=base*13%mod;
//	}
//	for(int i=1;i<=q;i++)
//	{
//		cin>>t1[i]>>t2[i];
//		if(t1[i].size()!=t2[i].size())
//		{
//			cout<<"0\n";
//			continue;
//		}
//		int base=1;
//		for(int j=1;j<=t1[i].size();j++) pre1[i]=(pre1[i]+hs[t1[i][j-1]-'a']*base%mod)%mod,base=base*13%mod;
//		base=1;
//		for(int j=1;j<=t2[i].size();j++) pre2[i]=(pre2[i]+hs[t2[i][j-1]-'a']*base%mod)%mod,base=base*13%mod;
//		
//		for(int j=1;j<=t1[i].size();j++)
//		{
//			for(int k=1;k<=n;k++)
//			{
//				if(j-s1[k].size()+1<=0) continue;
//				if(p[j-s1[k].size()]*h[k]==pre1[i]) 
//			}
//		}
//	}
//}

signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>q;
	for(int i=0;i<26;i++) hs[i]=rnd()%mod;
	p[0]=1;
	for(int i=1;i<N;i++) p[i]=13*p[i-1]%mod;
	solve1();
//	solve2();
	return 0;
}
