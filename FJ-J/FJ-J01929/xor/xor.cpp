#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10;
int n,k;
int a[N],x[N][N];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			x[i][j]=x[i][j-1] xor a[j];
		}
	}
	int ret=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if(x[i][j]==k)
			{
				ret++;
				i=j;
				break;
			}
		}
	}
	printf("%d",ret);
	return 0;
}

