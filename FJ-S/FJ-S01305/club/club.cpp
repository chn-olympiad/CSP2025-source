#include<iostream>
#include<algorithm>
using namespace std;
int n,t;
int a[3][200005],b[200005],c[200005],d[200005],num1 = 0,num2 = 0,num3 = 0,sum = 0;
int main()
{
	freopen("club.in ","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	for(int i = 0;i < t; i++)
	{
		cin >> n;
		for(int j = 1;j <= n; j++)
		{
			cin >> a[1][j] >> a[2][j] >> a[3][j];
			if(a[1][j] > a[2][j] && a[1][j] > a[3][j])
			{
				if(num1+1 <= n/2)
				{
					num1++;
					sum += a[1][j];
					b[num1] = a[1][j];
				}
				else
				{
					sort(b+1,b+num1+1);
					if(b[1] >= a[1][j] && max(a[2][j-1],a[3][j-1])+a[1][j] <= b[1])
					{
						if(a[2][j] > a[3][j])
						{
							num2 ++;
							sum += a[2][j];
						}
						else
						{
							num3 ++;
							sum += a[3][j];
						}
					}
					else if(max(a[2][j-1],a[3][j-1])+a[1][j] >= b[1])
					{
						sum -= b[1];
						sum += max(a[2][j-1],a[3][j-1])+a[1][j];
						b[1] = a[1][j];
					}
					else
					{
						sum -= b[1];
						sum += a[1][j];
						b[1] = a[1][j];
					}
				}
			}
			else if(a[2][j] > a[1][j] && a[2][j] > a[3][j])
			{
				if(num2+1 <= n/2)
				{
					num2 ++;
					sum += a[2][j];
					c[num2] = a[2][j];
				}
				else
				{
					sort(c+1,c+num2+1);
					if(c[1] >= a[2][j] && max(a[1][j-1],a[3][j-1])+a[2][j] <= c[1])
					{
						if(a[1][j] > a[3][j])
						{
							num1 ++;
							sum += a[1][j];
						}
						{
							num3 ++;
							sum += a[3][j];
						}
					}
					else if(max(a[1][j-1],a[3][j-1])+a[2][j] >= c[1])
					{
						sum -= c[1];
						sum += max(a[3][j-1],a[1][j-1])+a[2][j];
						c[1] = a[2][j];
					}
					else
					{
						sum -= c[1];
						sum += a[2][j];
						c[1] = a[2][j];
					}
				}
			}
			else
			{
				if(num3+1 <= n/2)
				{
					num3 ++;
					sum += a[3][j];
					d[num3] = a[3][j];
				}
				else
				{
					sort(d+1,d+num3+1);
					if(d[1] >= a[1][j] && max(a[2][j-1],a[1][j-1])+a[3][j] <= d[1])
					{
						if(a[1][j] > a[2][j])
						{
							num1 ++;
							sum += a[1][j];
						}
						else
						{
							num2 ++;
							sum += a[2][j];
						}
					}
					else if(max(a[2][j-1],a[3][j-1])+a[3][j] >= d[1])
					{
						sum -= d[1];
						sum += max(a[2][j-1],a[1][j-1])+a[3][j];
						d[1] = a[3][j];
					}
					else
					{
						sum -= d[1];
						sum += a[3][j];
						d[1] = a[3][j];
					}
				}
			}
		}
		cout << sum << endl;
		sum = 0;
		num1 = 0;
		num2 = 0;
		num3 = 0;
	}
	return 0;
}