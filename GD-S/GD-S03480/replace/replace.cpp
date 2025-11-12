#include<bits/stdc++.h>
using namespace std;
int n,m,len1[200005],len3[200005],bz[200005];
string s1[200005],s2[200005],s3[200005],s4[200005];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		cin>>s1[i]>>s2[i];
		len1[i]=s1[i].size();
	}
	for(int i=1;i<=m;i++)
	{
		cin>>s3[i]>>s4[i];
		len3[i]=s3[i].size();
	}
	for(int i=1;i<=m;i++)
	{
		int s=0;
		memset(bz,0,sizeof(bz));
		for(int l=1;l<=n;l++)
		{
			for(int j=0;j<len3[i];j++)
			{
				int flag=0;
				for(int k=0;k<len1[l];k++)
				{
					if(s3[i][j+k]!=s1[l][k])
					{
						flag=1;
					}
				}
				if(!flag&&!bz[l])
				{
					bz[l]=1;
					for(int k=0;k<len1[l];k++)
					{
						s3[i][j+k]=s2[l][k];
					}
					if(s3[i]==s4[i])
					{
						s++;
					}
					for(int k=0;k<len1[l];k++)
					{
						s3[i][j+k]=s1[l][k];
					}
				}
			}
		}
		printf("%d\n",s);
	}
}
