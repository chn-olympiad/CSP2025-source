#include<bits/stdc++.h>
#define int long long
using namespace std;
const int Base=10003,Mod=1e9+7;

int n,q,b[200005][2],p[200005],h1[200005],h2[200005];
string ss1,ss2;

struct SS
{
	string s1,s2;
}a[200005];

int get_hash(string s)
{
	int num=0;
	for(int i=0;i<s.size();i++)
	{
		num=(((num*Base)%Mod)+s[i])%Mod;
	}
	return num;
}

signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].s1>>a[i].s2;
		b[i][0]=get_hash(a[i].s1);
		b[i][1]=get_hash(a[i].s2);
	}
	p[0]=1;
	for(int i=1;i<=2e5+5;i++)
	{
		p[i]=p[i-1]*Base;
		p[i]%=Mod;
	}
	while(q--)
	{
		int ans=0;
		cin>>ss1>>ss2;
		h1[0]=h2[0]=0;
		for(int i=0;i<ss1.size();i++)
			h1[i+1]=(((h1[i]*Base)%Mod)+ss1[i])%Mod; 
		for(int i=0;i<ss2.size();i++)
		    h2[i+1]=(((h2[i]*Base)%Mod)+ss2[i])%Mod;
		for(int i=0;i<ss1.size();i++)
		{
			for(int j=1;j<=n;j++)
			{
			  int lens=a[j].s1.size();
			  if(ss1.size()-i<lens)
			    continue;
			  if(((h1[i+lens]-((h1[i]*p[lens])%Mod)%Mod)==b[j][0])&&((h2[i+lens]-((h2[i]*p[lens])%Mod)%Mod)==b[j][1]))
			  {
			  	bool ynn=1;
				for(int k=i+lens;k<ss1.size();k++)
				  if(ss1[k]!=ss2[k])
				    ynn=0;
				if(ynn)
				{
				  ans++;
				}
			  }
			}
			if(ss1[i]!=ss2[i])
			  break;
		}
		cout<<ans<<"\n";
	}
	return 0;
}
