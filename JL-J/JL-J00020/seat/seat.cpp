#include <bits/stdc++.h>
using namespace std;

int n,m,xjw,cntx;
int a[11][11];
int cj[101];
bool cmp(int x,int y)
{
	return x > y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	int xxxx = n*m;
	for (int i=1;i<=xxxx;i++)
		cin >> cj[i];
	int xj = cj[1];
	sort(cj+1,cj+xxxx,cmp);
	for (int i=1;i<=xxxx;i++){
		if (cj[i] == xj){
			xjw = i;break;}}
	for (int i=1;i<=n;i++)
	{
		if (i%2 == 1)
		{
			for (int j=1;j<=m;j++)
			{
				cntx++;
				a[j][i] = cntx;
			}
		}
		if (i%2 == 0)
		{
			for (int j=m;j>=1;j--)
			{
				cntx++;
				a[j][i] = cntx;
			}
		}
	}	
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++)
		{
			if (a[i][j] == xjw)
			{
				cout << j << ' ' << i;
				break;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
