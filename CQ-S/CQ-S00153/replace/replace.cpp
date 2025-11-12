#include<bits/stdc++.h>

using namespace std;
string s[200005][2];
string t1,t2,t3;
int cnt;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	scanf("%d %d",&n,&q);
	for(int i=1;i<=n;i++)
	{
		cin>>s[i][0]>>s[i][1];
	}
	for(int i=1;i<=q;i++)
	{
		cin>>t1>>t2;
		cnt=0;
		if(t1.size()!=t2.size())
		{
			printf("0\n");
			continue;
		}
		else
		{
			for(int j=1;j<=n;j++)
			{
				for(int k=0;k+s[j][0].size()<=t1.size();k++)
				{
					int o=1;
					for(int i2=k;i2<k+s[j][0].size();i2++)
					{
						if(t1[i2]!=s[j][0][i2-k])
						{
							o=0;
							break;
						}
					}
					if(o==1)
					{
						t3=t1;
						for(int i2=k;i2<k+s[j][0].size();i2++)
						{
							t3[i2]=s[j][1][i2-k];
						}
						if(t3==t2)
						{
							cnt++;
						}
					}
				}
			}
		}
		printf("%d\n",cnt);
	}
	return 0;
}
