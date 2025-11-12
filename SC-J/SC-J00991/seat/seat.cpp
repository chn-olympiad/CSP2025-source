#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[105];
int seat[15][15];
int i = 1,j = 1,k = 1;//i为行，j为列，k为第几个人
bool flag = 0;//0表示向下排，1相反
bool cmp(int x,int y)
{
	return x > y;
}
int num;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n >> m;
	for (int i = 1;i <= n * m;i++)
		cin >> a[i];
	num = a[i];
	sort(a + 1,a + 1 + n * m,cmp);
	while (true)
	{
		if (i > n && j > m)
			break;
		if (a[k] == num)
		{
			cout << j << " " << i;
			break;
		}
		if (i == n && flag == 0)
		{
			flag = 1;
			j++;
			k++;
		}
		else if (i == 1 && k != 1 && flag == 1)
		{
			flag = 0;
			j++;k++;
		}
		else if (flag == 0)
		{
			i++;k++;
		}
		else if (flag == 1)
		{
			i--;k++;
		}
	}
	return 0;
}
