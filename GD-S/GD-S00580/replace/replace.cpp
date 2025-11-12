#include<bits/stdc++.h>
using namespace std;
int n,q;
struct node
{
	string a;
	string b;
}s[200005];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)
	{
		cin>>s[i].a>>s[i].b;
	}
	while(q--)
	{
		int ans=0;
		string x,y;
		cin>>x>>y;
		for(int i=0;i<x.size();i++)
		{
			for(int j=i;j<x.size();j++)
			{
				string tmp1,tmp2;
				for(int k=i;k<=j;k++)
				{
					tmp1+=x[k];
					tmp2+=y[k];
				}
				for(int k=1;k<=n;k++)
				{
					if(s[k].a==tmp1)
					{
						if(s[k].b==tmp2)
						{
							string tmp3=x;
							for(int g=i;g<=j;g++)
							{
								tmp3[g]=y[g];
							}
							if(tmp3==y)
							{
								ans++;
							}
						}
					}
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
