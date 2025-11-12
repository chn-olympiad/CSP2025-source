#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	int a[110];
	cin >> n >> m;
	cin >> a[0];
	int s = a[0];
	for(int i=1;i<n*m;i++)
	{
		cin >> a[i];
	}
	sort(a,a+n*m);
	int num = 0;
	for(int i=n*m-1;i>=0;i--)
	{
		num++;
		if(a[i] == s)
		{
			break;
		}
	}
	int p, q;
	p = num / n + 1;
	int e = num % n;
	if(e == 0)
	{
		p -= 1;
	}
	if(p % 2 == 0)
	{
		q = n - e + 1;
		if(e==0)
		{
			q = 1;
		}
	} else {
		q = e;
		if(e==0)
		{
			q = n;
		}
	}
	cout << p << " " << q << endl;
	return 0;
}
