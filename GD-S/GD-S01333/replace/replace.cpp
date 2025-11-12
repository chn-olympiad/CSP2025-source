#include<bits/stdc++.h>
using namespace std;
string s1[200001],s2[200001];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q,l1,l2,ans;
	bool flag;
	string x,y,t;
	cin>>n>>q;
	for (int i=1;i<=n;i++)
	{
		cin>>s1[i]>>s2[i];
	}
	while (q--)
	{
		cin>>x>>y;
		ans=0;
		l1=x.size();
		for (int i=1;i<=n;i++)
		{
			l2=s1[i].size();
			for (int j=0;j<=l1-l2;j++)
			{
				t=x;
				flag=true;
				for (int k=0;k<l2;k++)
				{
					if (t[j+k]!=s1[i][k])
					{
						flag=false;
						break; 
					}
				}
				if (flag==false)
				{
					continue;
				}
				for (int k=0;k<l2;k++)
				{
					t[j+k]=s2[i][k];
				}
				if (t==y)
				{
					ans++;
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
