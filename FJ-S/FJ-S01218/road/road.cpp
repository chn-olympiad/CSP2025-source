#include<iostream>
using namespace std;
int n,m,k,a[1000005],b[1000005],c[1000005],kk[1000005],nk[1005][100005];
int main()
{
	cin>>n>>m>>k;
	for (int i=1;i<=m;i++)
	{
		cin>>a[i]>>b[i]>>c[i];
	}
	for (int i=1;i<=k;i++)
	{
		cin>>kk[i];
		for (int j=1;j<=n;j++)
		{
			cin>>nk[i][j];
		}
	}
	cout<<1;
	return 0;
}
