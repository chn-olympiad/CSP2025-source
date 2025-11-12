#include<bits/stdc++.h>
using namespace std;

string s1[200005],s2[200005];
string t1[200005],t2[200005];
int a1[200005],a2[200005],m1[200005];
int n,q;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int flaga=0;
	scanf("%d%d",&n,&q);
	for (int i=1;i<=n;i++)
	{
//		scanf("%s%s",&s1[i],&s2[i]);
		cin>>s1[i]>>s2[i]; 
		int m=s1[i].size();
		int c1=0,c2=0;
		for (int j=0;j<m;j++)
		{
			if (s1[i][j]=='a')
			{
				c1++;
			}
			if (s1[i][j]=='b')
			{
				c2++;
			}
		}
		if (c2!=1||c1+c2!=m)
		{
			flaga=1;
		}
		
		c1=0,c2=0;
		for (int j=0;j<m;j++)
		{
			if (s2[i][j]=='a')
			{
				c1++;
			}
			if (s2[i][j]=='b')
			{
				c2++;
			}
		}
		if (c2!=1||c1+c2!=m)
		{
			flaga=1;
		}
	}
	for (int i=1;i<=q;i++)
	{
//		scanf("%s%s",&t1[i],&t2[i]);
		cin>>t1[i]>>t2[i];
		int m=t1[i].size();
		int c1=0,c2=0;
		for (int j=0;j<m;j++)
		{
			if (t1[i][j]=='a')
			{
				c1++;
			}
			if (t1[i][j]=='b')
			{
				c2++;
			}
		}
		if (c2!=1||c1+c2!=m)
		{
			flaga=1;
		}
		
		m=t2[i].size();
		c1=0,c2=0;
		for (int j=0;j<m;j++)
		{
			if (t2[i][j]=='a')
			{
				c1++;
			}
			if (t2[i][j]=='b')
			{
				c2++;
			}
		}
		if (c2!=1||c1+c2!=m)
		{
			flaga=1;
		}
	}
	
	if (flaga==0)
	{
		for (int i=1;i<=n;i++)
		{
			int m=s1[i].size();
			m1[i]=m;
			for (int j=0;j<m;j++)
			{
				if (s1[i][j]=='b')
				{
					a1[i]=j;
					break;
				}
			}
			for (int j=0;j<m;j++)
			{
				if (s2[i][j]=='b')
				{
					a2[i]=j;
					break;
				}
			}
		}
		
		for (int i=1;i<=q;i++)
		{
			if (t1[i].size()!=t2[i].size())
			{
				printf("0\n");
				continue;
			}
			int x,y;
			int m=t1[i].size();
			for (int j=0;j<m;j++)
			{
				if (t1[i][j]=='b')
				{
					x=j;
					break;
				}
			}
			for (int j=0;j<m;j++)
			{
				if (t2[i][j]=='b')
				{
					y=j;
					break;
				}
			}
			
			int ans=0;
			for (int i=1;i<=n;i++)
			{
				if (x>=a1[i]&&(m-x)>=(m1[i]-a1[i]))
				{
					if (a1[i]-a2[i]==x-y)
					{
						ans++;
					}
				}
			}
			printf("%d\n",ans);
		}
	}
	else
	{
		for (int i=1;i<=n;i++)
		{
			int m=s1[i].size();
			m1[i]=m;
		}
		for (int i=1;i<=q;i++)
		{
			if (t1[i].size()!=t2[i].size())
			{
				printf("0\n");
				continue;
			}
			int m=t1[i].size();
			int x=m,y=-1;
			for (int j=0;j<m;j++)
			{
				if (t1[i][j]!=t2[i][j])
				{
					x=min(x,j);
					y=max(y,j);
				}
			}
			int ans=0;
			for (int j=1;j<=n;j++)
			{
				if (y-x+1>m1[j])
				{
					continue;
				}
				for (int l=0;l+m1[j]-1<=m-1;l++)
				{
					for (int r=l;r<=l+m1[j]-1;r++)
					{
						if (s1[j][r-l]!=t1[i][r]||s2[j][r-l]!=t2[i][r])
						{
							break;
						}
						if (r==l+m1[j]-1)
						{
							int flt=0;
							for (int k=0;k<m;k++)
							{
								if (l>k||k>r)
								{
									if (t1[i][k]!=t2[i][k])
									{
										flt=1;
										break;
									}
								}
							}
							if (flt==0)
							{
								ans++;
							}
						}
					}
				}
			}

			printf("%d\n",ans);
		}
	}
	return 0;
}

