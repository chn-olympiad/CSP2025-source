#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
const int N=105;
int a[N];
bool cmp(int x,int y)
{
	return x<y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=n*m;i++)
	{
		cin >> a[i];
	}
	int t=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==t)
		{
			break;
		}
	}
	int c=i/n+1;
	if(i%n==0)
	{
		cout << c-1 << " ";
	}
	else
	{
		cout << c << " ";
	}
	if(c%2==0)
	{
		cout << n-(i%n)+1;
	}
	else
	{
		cout << i%n;
	}
	return 0;
}