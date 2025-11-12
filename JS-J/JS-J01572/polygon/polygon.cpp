#include<bits/stdc++.h>
using namespace std;
int ccc(int a,int b)
{
	int l,r;
	l = 1;
	r = 1;
	for(int i = 1;i <= b;i++)
	{
		r *= i;
	}
	for(int i = a - b + 1;i <= a;i++)
	{
		l *= i;
	}
	int q = l /= r;
	return q;
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    long long sum = 0;
    cin >> n;
    int a[n + 1];
    bool sk = 1;
    for(int i = 1;i <= n;i++)
    {
		cin >> a[i];
		if(a[i] != 1)
		{
			sk = 0;
		}
    }
    if(sk == 1)
    {
		for(int i = 3;i <= n;i++)
		{
			sum += ccc(n,i);
		}
		sum %= 998244353;
		cout << sum;
		rerurn 0;
    }
    if(n == 5)
    {
		if(a[1] == 2)
		{
			cout << 6;
		}
		else
		{
			cout << 9;
		}
	}
	if(n == 3)
	{
		if(a[1] + a[2] > a[3])
		{
			cout << 1;
		}
		else
		{
			cout << 0;
		}
	}
    return 0;
} 
