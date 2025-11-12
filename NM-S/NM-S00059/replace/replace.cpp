#include <bits/stdc++.h>
using namespace std;
string s[200010][3],s1,s2;
int n,q;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)
	{
		cin >>s[i][1]>>s[i][2];
	}
	for(int i=1;i<=q;i++)
	{
		cin >>s1>>s2;
		int ans=0;
		if(s1.size()!=s2.size())
		{
			printf("0\n");
			continue;
		}
		for(int j=1;j<=n;j++)
		{
			for(int k=0;k<s1.size()-s[j][1].size()+1;k++)
			{
				int l=k,f=1;
				for(int o=0;o<k;o++)
				{
					if(s1[o]!=s2[o])
					{
						f=0;
						break;
					}
				}
				for(int o=k+s[j][1].size();o<s1.size();o++)
				{
					if(s1[o]!=s2[o])
					{
						f=0;
						break;
					}
				}
				if(!f) continue;
				while(l-k<s[j][1].size() and s1[l]==s[j][1][l-k] and s2[l]==s[j][2][l-k])
					l++;
				if(l==k+s[j][1].size())
					ans++;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}