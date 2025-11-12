#include<bits/stdc++.h>
//#define int long long
using namespace std;
const int N=2e5+10,Mod=998244353,inf=1e9+10;
int n,m,cnt;
string s[N];
unordered_map<string,string> mp;
int qpow(int x,int y)
{
	int res=1;
	while(y)
	{
		if(y&1) res*=x,res%=Mod;
		x*=x,x%=Mod,y>>=1;
	}
	return res;
}
signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		string s2;
		cin>>s[i]>>s2;
		mp[s[i]]=s2;
	}
	while(m--)
	{
		cnt=0;
		string s1,s2;
		cin>>s1>>s2;
		if(s1.length()!=s2.length())
		{
			cout<<0<<'\n';
			continue;
		}
		int l,r;
		for(int i=0;i<s1.length();i++) if(s1[i]!=s2[i]) 
		{
			l=i;
			break;
		}
		for(int i=s1.length();i>=0;i--) if(s1[i]!=s2[i])
		{
			r=i;
			break;
		}
		int le=r-l+1;
//		cout<<l<<' '<<r<<'\n';
		for(int i=1;i<=n;i++)
		{
			if(s[i].length()<le) continue;
			for(int j=r-s[i].length();j<=l;j++) if(s1[j]==s[i][0])
			{
				string nw,to;
				for(int k=0;k<s[i].length();k++) nw+=s1[j+k],to+=s2[j+k];
				if(nw==s[i]&&to==mp[s[i]]) cnt++;
			}
		}
		cout<<cnt<<'\n';
	}
	return 0;
}
