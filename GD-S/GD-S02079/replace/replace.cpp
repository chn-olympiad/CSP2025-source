#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<fstream>
using namespace std;
int n,m,u,v,p,q,w_ans,l[105];
bool w_is,a[2005];
char s[105][2005],t[105][2005],x[2005],y[2005];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%s %s",s[i]+1,t[i]+1);
		l[i]=strlen(s[i]+1);
	}
	while(m--)
	{
		scanf("%s %s",x+1,y+1);
		u=strlen(x+1);
		v=strlen(y+1);
		if(u!=v)
		{
			printf("0\n");
			continue;
		}
		for(int i=1;i<=u;i++)
		{
			if(x[i]!=y[i])
				a[i]=1;
			else
				a[i]=0;
		}
		p=0;
		q=0;
		w_is=0;
		w_ans=0;
		for(int i=1;i<=u;i++)
		{
			if(a[i])
			{
				if(!a[i-1])
				{
					if(p||q)
					{
						w_is=1;
						break;
					}
					else
						p=q=i;
				}
				else
					q++;
			}
		}
		if(w_is)
		{
			printf("0\n");
			continue;
		}
		for(int i=1;i<=n;i++)
		{
			if(l[i]==q-p+1)
			{
				w_is=0;
				for(int j=1;j<=l[i];j++)
				{
					if(s[i][j]!=x[p+j-1]||t[i][j]!=y[p+j-1])
					{
						w_is=1;
						break;
					}
				}
				if(!w_is)
					w_ans++;
			}
			else
			{
				for(int j=1;j<=u&&j+l[i-1]<=u;j++)
				{
					if(p<j||q>j+l[i]-1)
						continue;
					w_is=0;
					for(int e=1;e<=l[i];e++)
					{
						if(s[i][e]!=x[j+e-1]||t[i][e]!=y[j+e-1])
						{
							w_is=1;
							break;
						}
					}
					if(!w_is)
						w_ans++;
				}
			}
		}
		printf("%d\n",w_ans);
	}
	return 0;
}
