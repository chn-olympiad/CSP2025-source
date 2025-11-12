#include<bits/stdc++.h>
typedef long long ll;
const ll N=200005;
using namespace std;
ll n,q;
string s[N][2],s1,s2;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%lld %lld",&n,&q);
	for(ll i=1;i<=n;i++)
	{
		cin>>s[i][0]>>s[i][1];
	}
	while(q--)
	{
		cin>>s1>>s2;
		if (s1.size()!=s2.size())
		{
			printf("0\n");
			continue;
		}
		int ans=0;
		for(ll i=1;i<=n;i++)
		{
			bool b1=true,b2=true,b3=true;
			for(ll j=0;j<=s1.size()-1;j++)
			{
				if (j!=0)
				{
					if (s1[j-1]!=s2[j-1])
					{
						break;
					}
				}
				if (j+s[i][0].size()-1>s1.size()-1)
				{
//					printf("%lld %lld 1\n",i,j);
					continue;
				}
				for(ll k=0;k<=s[i][0].size()-1;k++)
				{
					if (s1[j+k]!=s[i][0][k])
					{
						b1=false;
//						printf("%lld %lld %lld %c %c\n",i,j,k,s1[j+k],s[i][0][k]);
//						printf("%lld 1\n",k);
						break;
					}
				}
				if (!b1)
				{
//					printf("%d\n",j);
					continue;
				}
				for(ll k=0;k<=s[i][1].size()-1;k++)
				{
					if (s2[j+k]!=s[i][1][k])
					{
						b2=false;
//						printf("%lld %lld %lld %c %c\n",i,j,k,s2[j+k],s[i][1][k]);
						break;
					}
				}
				if (!b2)
				{
					continue;
				}
				for(ll k=j+s[i][0].size()-1;k<=s1.size()-1;k++)
				{
					if (s1[k]!=s2[k])
					{
						b3=false;
//						printf("%lld %lld %lld\n",i,j,k);
						break;
					}
				}
				if (!b3)
				{
					continue;
				}
				ans++;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
