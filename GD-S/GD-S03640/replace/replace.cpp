#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+5;
ll n,q,dp[5000005],ans;
string s1[N],s2[N];
char c[5000005],c2[5000005];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%lld%lld",&n,&q);
	for(int i=1;i<=n;i++)
	{
		scanf("%s",c+1);
		ll len=strlen(c+1);
		for(int j=1;j<=len;j++)
		{
			s1[i]=s1[i]+c[j];
		}
		scanf("%s",c+1);
		for(int j=1;j<=len;j++) s2[i]=s2[i]+c[j];
	}
	while(q--)
	{
		string c1,c3;
		cin>>c1>>c3;
		ll len1=c1.size(),len2=c3.size();
		c1='#'+c1;
		c3='#'+c3;
		if(len1!=len2)
		{
			printf("0\n");
			continue;
		}
		ans=0;
		for(int i=1;i<=n;i++)
		{
			bool flag=true;
			ll aaa=0;
			for(int j=1;j<=len1;j++)
			{
				ll pos1=c1.find(s1[i],j),pos2=c3.find(s2[i],j);
				if(pos1==pos2&&pos1!=-1)
				{
					j=pos1+s1[i].size()-1;
				}
				else
				{
					if(c1[j]!=c2[j])
					{
						flag=false;
						break;
					}
					if((pos1!=-1&&pos2==-1)||(pos1==-1&&pos2!=-1))
					{
						flag=false;
						break;
					}
				}
			}
			if(flag==true) ans++;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb
*/
