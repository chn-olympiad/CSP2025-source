#include <bits/stdc++.h>
using namespace std;
long long n,m,a[10005],num;
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	cin >> a[1];
	num=a[1];
	for(int i=2;i<=n*m;i++)
	{
		cin >> a[i];
	}
	sort(a+1,a+(n*m)+1,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==num)
		{
			int x=i/n;
			int y=i%n;
			if(y!=0)
			{
				x++;
			}
			else
			{
				y=m;
			}
			if(x%2==1)
			{
				cout << x << " " << y;
				break;
			}
			else
			{
				cout << x << " " << m-y+1;
				break;
			}
		}
	}
	return 0;
}
