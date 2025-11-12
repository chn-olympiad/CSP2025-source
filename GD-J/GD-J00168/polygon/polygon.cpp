#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;

int main();
bool comp(int *x,int *y);

int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	int n;
	cin >> n;
	int l[n];
	for(int i = 0;i < n;i++)
	{
		cin >> l[i];
	}
	comp(l,l + n + 1);
	
	if(n = 3)
	{
		cout << 1;
		return 0;
	}
	int a[n] = {0,0,0},t;
	for(int i = 3;i <= n;i++)
	{
		a[i - 1] = 1;
		for(int t = n;t > n - i;t--)
		{
			a[i - 1] *= t;
		}
		for(int t = 1;t <= i;t++)
		{
			a[i - 1] /= t;
		}
	}
	t = 0;
	for(int i = 0;i < n;i++)
	{
		t += a[i];
	}
	cout << t;
	
	return 0;
}
bool comp(int *x,int *y)
{
	return x < y;
}
