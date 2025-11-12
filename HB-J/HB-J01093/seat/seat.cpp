#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+ 5;
long long n,m,b,sum=1,x=1,y=1;
int a[N];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	b = a[1];
	for(int i = 1;i<=n*m;i++)
	{
		if(a[i]>b)
		{
			sum++;
		}
	}
	if(sum%n!=0)
	{
		x = sum / n + 1;
		sum = sum - n*x;
	}
	else
	{
		x = sum / n ;
		sum = sum - n*x;
		}
	if(x%2==0)
	{
		y=m;
		y = y-sum/n;
	}
	else
	{
		y = y+sum/n;
	}
	cout<<x<<" "<<y;
	return 0;
}
