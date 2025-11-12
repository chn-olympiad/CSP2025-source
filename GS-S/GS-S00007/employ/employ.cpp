#include<bits/stdc++.h>
#include<cstring>
#include<cstdio>
using namespace std;
char s[100];
int sa[1000],b[1000];
int main()
{
//	freopen("club.in","r",stdin);
//	freopen("club.out","w",stdout);
	int ls,n,m,u,a;
	cin>>n>>m;
	scanf("%s",s);
	ls=strlen(s);
	for(int i=0;i<ls;i++)
	{
		sa[i]=s[i]-'0';
	}
	
	for(u=0;u<ls;u++)
	{
		cin>>b[u];
	}
	for(int i=0;i<u;i++)
	{
		if(sa[i]==1)
		{
			for(int j=i;j<u;j++)
			{
				
			}
		}
	}
	return 0;
}
