#include<bits/stdc++.h>
using namespace std;
string s[2][200010];
int a[2][200010],l[200010];
//set<int> ca[10000010];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)
	{
		cin>>s[0][i];
		cin>>s[1][i];
		l[i]=s[0][i].size();
		for(a[0][i]=0;a[0][i]<l[i];a[0][i]++)
		{
			if(s[0][i][a[0][i]]!=s[1][i][a[0][i]])
			{
				break;
			}
		}
		for(a[1][i]=l[i]-1;~a[1][i];a[1][i]--)
		{
			if(s[0][i][a[1][i]]!=s[1][i][a[1][i]])
			{
				break;
			}
		}
	}
	while(q--)
	{
		string t1,t2;
		cin>>t1>>t2;
		int len=t1.size(),s1,s2;
		for(s1=0;s1<len;s1++)
		{
			if(t1[s1]!=t2[s1])
			{
				break;
			}
		}
		for(s2=len-1;~s2;s2--)
		{
			if(t1[s2]!=t2[s2])
			{
				break;
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			if(s1+a[1][i]!=s2+a[0][i])
			{
				continue;
			}
			int f=0;
			for(int j=s1-a[0][i];j<s2+l[i]-a[1][i];j++)
			{
				if(t1[j]!=s[0][i][j+a[0][i]-s1]||t2[j]!=s[1][i][j+a[0][i]-s1])
				{
					f=1;
					break;
				}
			}
			if(!f)
			{
				ans++;
			}
		}
		printf("%d\n",ans);
	}
	/*else
	{
		for(int i=1;i<=n;i++)
		{
			cin>>s[0][i];
			cin>>s[1][i];
			l[i]=s[0][i].size();
			int a1,a2;
			for(int j=0;j<l[i];j++)
			{
				if(s[0][i][j]=='b')
				{
					a1=j;
				}
				if(s[1][i][j]=='b')
				{
					a2=j;
				}
			}
			ca[a2-a1+5000000][0].emplace(a1);
		}
		while(q--)
		{
			string t1,t2;
			cin>>t1>>t2;
			int len=t1.size(),s1,s2;
			for(s1=0;s1<len;s1++)
			{
				if(t1[s1]!=t2[s1])
				{
					break;
				}
			}
			for(s2=len-1;~s2;s2--)
			{
				if(t1[s2]!=t2[s2])
				{
					break;
				}
			}
			int ans=0;
			for(int i=1;i<=n;i++)
			{
				if(s1+a[1][i]!=s2+a[0][i])
				{
					continue;
				}
				int f=0;
				for(int j=s1-a[0][i];j<s2+l[i]-a[1][i];j++)
				{
					if(t1[j]!=s[0][i][j+a[0][i]-s1]||t2[j]!=s[1][i][j+a[0][i]-s1])
					{
						f=1;
						break;
					}
				}
				if(!f)
				{
					ans++;
				}
			}
			printf("%d\n",ans);
		}
	}*/
	return 0;
}
