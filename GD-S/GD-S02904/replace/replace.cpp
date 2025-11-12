#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
inline int read()
{
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')x=(x<<3)+(x<<1)+(c^48),c=getchar();
	return x*f; 
}
int n,m,len[2010];
char s[2][2010][2010],ch[2010],t1[2010],t2[2010];
signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++)
	{
		scanf("%s",ch+1);
		len[i]=strlen(ch+1);
		for(int j=1;j<=len[i];j++)s[0][i][j]=ch[j];
		scanf("%s",ch+1);
		for(int j=1;j<=len[i];j++)s[1][i][j]=ch[j];
	}
	while(m--)
	{
		scanf("%s %s",t1+1,t2+1);
		if(n>2000)
		{
			puts("0");
			continue;
		}
		int lt=strlen(t1+1),ans=0;
		for(int i=1;i<=n;i++)
		{
			if(len[i]>lt)continue;
			for(int l=1;l+len[i]-1<=lt;l++)
			{
				int r=l+len[i]-1;bool flag=1;
				for(int u=l,v=1;u<=r;u++,v++)if(t1[u]!=s[0][i][v])
				{
					flag=0;
					break;
				}
				if(flag)
				{
					for(int j=1;j<=lt;j++)ch[j]=t1[j];
					for(int u=l,v=1;u<=r;u++,v++)ch[u]=s[1][i][v];
					for(int j=1;j<=lt;j++)if(ch[j]!=t2[j])flag=0;
					if(flag)++ans;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
/*
*/
