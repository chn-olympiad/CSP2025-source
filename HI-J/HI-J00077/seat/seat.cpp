#include <bits/stdc++.h>
using namespace std;
int a[1000005];
bool c(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,d;
	cin >> n >> m;
	int s=n*m;
	cin >> d;
	a[1]=d;
	for(int i=2;i<=s;i++)
	{
		cin >> a[i];
	}
	sort(a+1,a+s+1,c);
	for(int i=1;i<=s;i++)
	{
		if(a[i]==d)
		{
			if(i<n)
			{
				cout << "1" << " " << i;
				break;
			}
			int q=i/n+1;
			cout << q << " ";
			if(q/2==1)
			{
				cout << i%n+1;
			}
			else
			{
				cout << n-i%n+1;
			}
			break;
		}
	}
	return 0;
}
