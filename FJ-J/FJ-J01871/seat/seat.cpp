#include <bits/stdc++.h>
using namespace std;
int a[101];
int b[11][11];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int fs;
	int n, m;
	cin >> n >> m;
	for(int i=1;i<=n*m;i++)
	cin >> a[i];
	fs=a[1];
	for(int i=1;i<=n*m-1;i++)
	for(int j=i+1;j<=n*m;j++)
	if(a[i]<a[j])
	swap(a[i], a[j]);
	int bj=1;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	{
		if(i%2==1)
		{
			b[i][j]=a[bj];
			bj++;
		}
		if(i%2==0)
		{
			b[i][m+1-j]=a[bj];
			bj++;
		}
	}
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	{
		if(b[i][j]==fs)
		cout << i << " " << j;
	}
	return 0;
}