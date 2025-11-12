#include <bits/stdc++.h>
using namespace std;
int n,m,mark,a[102],sum,x,y;
bool cmp(int a,int b)
{
	return a > b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n*m;i++)
	{
		cin >> a[i];
		if (i == 1)
			mark = a[i];
	}
	sort (a+1,a+n*m+1,cmp);
	if (mark > 50)
	{
		sum = 1;
		while (a[sum] != mark)
			sum++;
	}
	else
	{
		sum = 101;
		while (a[sum] != mark)
			sum--;
	}
	if (sum % n == 0 && (sum / n) % 2 == 1)
	{
		x = sum / n;
		y = n;
	}
	else if (sum % n == 0 && (sum / n) % 2 == 0)
	{
		x = sum / n;
		y = 1;
	}
	else if ((sum / n + 1) % 2 == 0)
	{
		x = sum / n + 1;
		y = n*x+1-sum;
	}
	else
	{
		x = sum / n + 1;
		y = sum - (n*(x-1));
	}
	cout << x <<" "<< y;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
