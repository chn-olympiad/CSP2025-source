#include <iostream>
#include <cmath>
using namespace std;
int n,k;
int a[10000];
int tem[10000][2];
int xorr(int x,int y);
int xorr(int x,int y)
{
	int jieguo=a[x];
	for (int i=x+1;i<=y;i++)
	{
		jieguo=jieguo^a[i];
	}
	return jieguo;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for (int i=0;i<n;i++)
	{
		cin >> a[i];
	}
	int temlong=0;
	for (int i=0;i<n;i++)
	{
		for (int j=i;j<n;j++)
		{
			if(xorr(i,j)==k)
			{
				tem[temlong][0]=i;
				tem[temlong][1]=j;
				temlong++;
			}
		}
	}
	int maxx=0;
	for (int i=0;i<=temlong;i++)
	{
		for (int j=0;j<=temlong;j++)
		{
			if (i!=j && max(tem[i][0],tem[j][0])-min(tem[i][1],tem[j][1])>0 && tem[i][1]-tem[i][0]>maxx)
			{
				maxx=tem[i][1]-tem[i][0];
			}
		}
	}
	cout << maxx;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
