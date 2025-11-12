#include<bits/stdc++.h>
using namespace std;
long long n,m,ans,cz,yl,nn;
long long c[1000],pa[1000],u[1000];
char s[1000];
bool z;
int pai(int w)
{
	for(int i=1;i<=n;i++)
	{
		if(u[i]==0)
		{
			pa[w]=i;
			u[i]=1;
			if(w<n)
			{
				pai(w+1);
			}
			else
			{
//				for(int j=1;j<=n;j++)
//				{
//					printf("%d ",pa[j]);
//				}
//				printf("\n");
				cz=0;
				yl=0;
				for(int j=1;j<=n;j++)
				{
					z=1;
					while(1)
					{
//						printf("%d:%d/%d ",pa[cz+yl+1],cz,c[pa[cz+yl+1]]);
						if(cz<c[pa[cz+yl+1]])
						{
							break;
						}
						else
						{
//							printf("0 ");
							cz++;
						}
						if(yl+cz==n)
						{
							z=0;
							break;
						}
					}
					if(z==0)
					{
						break;
					}
					if(s[j]=='1')
					{
//						printf("2 ");
						yl++;
					}
					else
					{
//						printf("1 ");
						cz++;
					}
					if(yl==m)
					{
						ans++;
						ans%=998244353;
						break;
					}
					if(cz+yl==n)
					{
						break;
					}
				}
//				printf("\n");
			}
			u[i]=0;
		}
	}
}
int main()
{
	int z111;
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("%c",&s[0]);
	z111=1;
	nn=n;
	for(int i=1;i<=n;i++)
	{
		scanf("%c",&s[i]);
		if(s[i]=='0')
		{
			z111=0;
		}
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&c[i]);
		if(c[i]==0)
		{
			nn--;
		}
	}
	if(z111)
	{
		for(int i=1;i<=nn;i++)
		{
			ans*=i;
			ans%=998244353;
		}
		cout<<ans;
		return 0;
	}
	pai(1);
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
