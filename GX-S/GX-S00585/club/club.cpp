#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int s[100000+10][4],n,t;
const int modn=20;
int f[modn][modn][modn][modn],ans=0;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		memset(f,0,sizeof(f));
		memset(s,0,sizeof(s));
		scanf("%d",&n);
		ans=0;
		for(int i=1;i<=n;i++)
			scanf("%d%d%d",&s[i][1],&s[i][2],&s[i][3]);
		for(int i=1;i<=n;i++)
		{
			for(int a=0;a<=n/2;a++)
				for(int b=0;b<=n/2;b++)
					for(int c=0;c<=n/2&&a+b+c<=i;c++)
					{
						if(a>=1)
							f[i%modn][a%modn][b%modn][c%modn]=f[(i-1+modn)%modn][(a-1+modn)%modn][b%modn][c%modn]+s[i][1];
						if(b>=1)
							f[i%modn][a%modn][b%modn][c%modn]=max(f[i%modn][a%modn][b%modn][c%modn],f[(i-1+modn)%modn][a%modn][(b-1+modn)%modn][c%modn]+s[i][2]);
						if(c>=1)
							f[i%modn][a%modn][b%modn][c%modn]=max(f[i%modn][a%modn][b%modn][c%modn],f[(i-1+modn)%modn][a%modn][b%modn][(c-1+modn)%modn]+s[i][3]);
						if(a+b+c==n)
							ans=max(ans,f[i%modn][a%modn][b%modn][c%modn]);
					}
		}
		cout<<ans<<endl;
	}
	return 0;
}
