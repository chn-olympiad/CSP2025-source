#include<bits/stdc++.h>
using namespace std;
int n,q,mf,ml,ans;
int sl[2000],tl[2000];
char c,s[2000][2][100000],t[2000][2][100000];
bool z;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	scanf("%c",&c);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;;j++)
		{
			scanf("%c",&s[i][1][j]);
			if(s[i][1][j]==' ')
			{
				break;
			}
			sl[i]++;
		}
		for(int j=1;;j++)
		{
			scanf("%c",&s[i][2][j]);
			if(s[i][2][j]=='\n')
			{
				break;
			}
		}
	}
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=1;j<=sl[i];j++)
//		{
//			printf("%c",s[i][1][j]);
//		}
//		printf(" ");
//		for(int j=1;j<=sl[i];j++)
//		{
//			printf("%c",s[i][2][j]);
//		}
//		printf("\n");
//	}
	for(int i=1;i<=q;i++)
	{
		ans=0;
		for(int j=1;;j++)
		{
			scanf("%c",&t[i][1][j]);
			if(t[i][1][j]==' ')
			{
				break;
			}
			tl[i]++;
		}
		for(int j=1;;j++)
		{
			scanf("%c",&t[i][2][j]);
			if(t[i][2][j]=='\n')
			{
				break;
			}
		}
		for(int j=1;j<=tl[i];j++)
		{
			if(t[i][1][j]!=t[i][2][j])
			{
				mf=j;
				break;
			}
		}
		for(int j=tl[i];j>=1;j--)
		{
			if(t[i][1][j]!=t[i][2][j])
			{
				ml=j;
				break;
			}
		}
		for(int imf=mf;imf>=1;imf--)
		{
			for(int iml=ml;iml<=tl[i];iml++)
			{
				for(int j=1;j<=n;j++)
				{
					if(sl[j]==iml-imf+1)
					{
						z=1;
						for(int k=1;k<=sl[j];k++)
						{
							if(s[j][1][k]!=t[i][1][k+imf-1]||s[j][2][k]!=t[i][2][k+imf-1])
							{
								z=0;
								break;
							}
						}
						if(z)
						{
							ans++;
						}
					}
				}
			}
		}
		printf("%d\n",ans);
	}
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}
