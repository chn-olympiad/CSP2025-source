#include<bits/stdc++.h>
using namespace std;
#define p 998244353
int n,q,bas=1145141,pw[10000001];
string s[200001][2],t[200001][2];
vector<int>sh[200001][2],th[200001][2];
long long hass(int i,bool op,int l,int r){return((sh[i][op][r]-1ll*(l?sh[i][op][l-1]:0)*pw[r-l+1])%p+p)%p;}
long long hast(int i,bool op,int l,int r){return((th[i][op][r]-1ll*(l?th[i][op][l-1]:0)*pw[r-l+1])%p+p)%p;}
signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=pw[0]=1;i<=10000000;i++)pw[i]=1ll*pw[i-1]*bas%p;
	for(int i=1;i<=n;i++)cin>>s[i][0]>>s[i][1];
	for(int i=1;i<=q;i++)cin>>t[i][0]>>t[i][1];
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<s[i][0].size();j++)
		{
			if(j)sh[i][0].push_back((1ll*sh[i][0][j-1]*bas+s[i][0][j])%p);
			else sh[i][0].push_back(s[i][0][j]);
		}
		for(int j=0;j<s[i][1].size();j++)
		{
			if(j)sh[i][1].push_back((1ll*sh[i][1][j-1]*bas+s[i][1][j])%p);
			else sh[i][1].push_back(s[i][1][j]);
		}
	}
	for(int i=1;i<=q;i++)
	{
		for(int j=0;j<t[i][0].size();j++)
		{
			if(j)th[i][0].push_back((1ll*th[i][0][j-1]*bas+t[i][0][j])%p);
			else th[i][0].push_back(t[i][0][j]);
		}
		for(int j=0;j<t[i][1].size();j++)
		{
			if(j)th[i][1].push_back((1ll*th[i][1][j-1]*bas+t[i][1][j])%p);
			else th[i][1].push_back(t[i][1][j]);
		}
	}
	for(int i=1;i<=q;i++)
	{
		int res=0,pre=-1,suf=t[i][0].size();
		while(pre<suf-1)
		{
			if(t[i][0][pre+1]!=t[i][1][pre+1])break;
			++pre;
		}
		while(suf>1)
		{
			if(t[i][0][suf-1]!=t[i][1][suf-1])break;
			--suf;
		}
		for(int j=0;j<=pre+1;j++)
		{
			for(int k=1;k<=n;k++)
			{
				if(j+s[k][0].size()-1>=t[i][0].size())continue;
				if(j+s[k][0].size()-1<suf-1)continue;
				if(hass(k,0,0,s[k][0].size()-1)!=hast(i,0,j,j+s[k][0].size()-1))continue;
				if(hass(k,1,0,s[k][1].size()-1)==hast(i,1,j,j+s[k][1].size()-1))++res;
			}
		}
		printf("%d\n",res);
	}
	return 0;
}
