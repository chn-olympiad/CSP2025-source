#include <bits/stdc++.h>
#define ULL unsigned long long
using namespace std;
const int N=5e6+5;
map<pair<ULL,ULL>,int> mp;
char s[N],t[N];
ULL in[N];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	for(int i=1;i<=5000000;i++) in[i]=in[i-1]*1331;
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%s",s);
		scanf("%s",t);
		ULL x=0,y=0;
		int len=strlen(s);
		for(int j=0;j<len;j++)
		{
			x=x*1331+s[j];
			y=y*1331+t[j];
		}
		mp[{x,y}]++;
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%s%s",s,t);
		int len=strlen(s);
		int l=len,r=0;
		for(int j=0;j<len;j++)
		{
			if(s[j]!=t[j])
			{
				l=min(l,j);
				r=j;
			}
		}
		int ans=0;
		for(int j=0;j<=l;j++)
		{
			ULL ha1=0,ha2=0;
			for(int k=j;k<r;k++)
			{
				ha1=ha1*1331+s[k];
				ha2=ha2*1331+t[k];
			}
			for(int k=r;k<len;k++)
			{
				ha1=ha1*1331+s[k];
				ha2=ha2*1331+t[k];
				ans+=mp[{ha1,ha2}];
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}

