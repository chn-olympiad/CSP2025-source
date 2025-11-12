#include<bits/stdc++.h>
using namespace std;
int n,m,s[505],c[505],f[505][505];
const int mod=998244353;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%1d",&s[i]);
	for(int i=1;i<=n;i++) scanf("%d",&c[i]);
	sort(c+1,c+1+n);
	f[0][0]=1;
	for(int i=1;i<=n;i++)
	{
		f[i][0]=1;
		for(int j=1;j<=i;j++)
		{
			if(s[i]==0)
			{
				f[i][j]=f[i-1][j];
				continue;
			}
			int tot=0;
			for(int k=1;k<=n-i+j;k++){if(c[k]>i-j) tot++;}
			f[i][j]=(f[i-1][j-1]*(tot%mod))%mod;
		}
	}
	printf("%d",f[n][m]);
	return 0;
}

