#include<bits/stdc++.h>
using namespace std;

int m,n;
int s;
int a[10005];
long long ans;


int main()
{	
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	cin >> s;
	a[s]++;
	for(int i = 2;i <= n*m;i++)
	{
		int x;
		cin >> x;
		a[x]++;
		
	}
	
	for(int i = 100;i >= s;i--)
	{
		ans += a[i];
	}
	
	/*
	for(int i = 1;i <= n*m;i++)
	{
		cout << a[i] << " ";
	}
	*/
	
	//cout << ans;
	//x lie  y hang
	long long x = ans / n,y = ans % n;
	if(y != 0) x++;
	if(x % 2 == 1 && y == 0)
	{
		 y = n - y;
	}
	else if(x % 2 == 0)
	{
		y++;
	}
	cout << x << " " << y << endl;
	return 0;
}
