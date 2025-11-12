#include <bits/stdc++.h>
using namespace std;
int n,m,a[1005][1005],pnts[1005],pnt;
bool cmp(int a,int b)
{
	return a>b;
}
int main() 
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for (int i = 1;i<=n*m;i++)
	{
		cin>>pnt;
		pnts[i] = pnt; 
	}
	int qpnt = pnts[1];
	int isbr = false,wxx=false,wss=false;
	sort(pnts+1,pnts+n*m+1,cmp);
	int cnt=1;
	for (int j = 1;j<=n;)
	{
		bool isdb=false;
		bool isdingb=false;
		for (int i = 1;i<=m;)
		{
			if (i==1&&j==1)
			{
				a[j][i]=pnts[cnt];
				j++;
				cnt++;
			}
			else if(j==n&&i<m)
			{
				a[j][i]=pnts[cnt];
				if (isdb==false)
				{
					i++;
					isdb = true;
					cnt++;
				}
				else if(isdb==true)
				{
					j--;
					isdb=false;
					wss = true;
					wxx=false;
					cnt++;
				}
			}
			else if(j<n&&i<m)
			{
				a[j][i] = pnts[cnt];
				if (j==1&&isdingb==false)
				{
					isdingb = true;
					cnt++;
					i++;
				}
				else if(j==1&&isdingb==true)
				{
					cnt++;
					isdingb = false;
					wxx = true;
					wss=false;
					j++;
				}
				else
				{
					//看看往上上还是往下下
					if (wxx==true)
					{
						cnt++;
						j++;
					}
					else if(wss==true)
					{
						cnt++;
						j--;
					}
				}
			}
			else if (i==m&&j<n)
			{
				a[j][i] = pnts[cnt];
				j++;
				cnt++;
			}
			if (i==m&&j==n)
			{
				a[j][i] = pnts[cnt];
				isbr=true;
				break;
			}
		}
		if (isbr = true)
		{
			break;
		}
	}
	int stop = false;
	for (int i = 1;i<=n;i++)
	{
		for (int j = 1;j<=m;j++)
		{
			if (qpnt==a[i][j]&&stop==false)
			{
				cout << j<<" "<<i;
				stop = true;
			}
		}
	}
	return 0;
}
