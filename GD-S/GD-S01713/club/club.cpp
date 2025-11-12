#include <bits/stdc++.h> 
using namespace std;
struct stu
{
	int a,b,c;
}s[3];
int f[7];
int p[7];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n;
	scanf("%d",&t);
	for (int l=1;l<=t;l++)
	{
		scanf("%d",&n);
		if (n==2)
		{
			for (int i=1,j=1;i<=n;i++,j+=3)
			{
				scanf("%d%d%d",&s[i].a,&s[i].b,&s[i].c);
				if (s[i].a>s[i].b && s[i].a>s[i].c)
				{
					f[j]=s[i].a;
					p[j]=1;
					if (s[i].b>s[i].c)
					f[j+1]=s[i].b;
					else 
					f[j+1]=s[i].c;
				}
				if (s[i].b>s[i].a && s[i].b>s[i].c)
				{
					f[j]=s[i].b;
					p[j]=2;
					if (s[i].a>s[i].c)
					f[j+1]=s[i].a;
					else 
					f[j+1]=s[i].c;
				}
				if (s[i].c>s[i].b && s[i].c>s[i].a)
				{
					f[j]=s[i].c;
					p[j]=3;
					if (s[i].b>s[i].a)
					f[j+1]=s[i].b;
					else 
					f[j+1]=s[i].a;
				}
			}
			if (p[1]==p[4])
			printf("%d\n",max(f[1]+f[5],f[2]+f[4]));
			else 
			printf("%d\n",f[1]+f[4]);
		}
	}
	return 0;
}
