#include<bits/stdc++.h>
using namespace std;

long long n,m,a[200],t;

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	if(n == 1 && m == 1)
	{
		cout << 1 << " " << 1;
	}
	else if(n == 1 && m >= 2)
	{
		for(int i=1;i<=m;i++)
		{
			cin >> a[i];
			if(a[i] > a[1])
			{
				t++;
			}
		}
		cout << t+1 << " " << 1;
	}
	else if(m == 1 && n >= 2)
	{
		for(int i=1;i<=n;i++)
		{
			cin >> a[i];
			if(a[i] > a[1])
			{
				t++;
			}
		}
		cout << 1 << " " << t+1;
	}
	else if(n == 2 && m == 2)
	{
		for(int i=1;i<=n*m;i++)
		{
			cin >> a[i];
			if(a[i] > a[1])
			{
				t++;
			}
		}
		if(t == 0)
		{
			cout << 1 << " " << 1;
		}
		else if(t == 1)
		{
			cout << 1 << " " << 2;
		}
		else if(t == 2)
		{
			cout << 2 << " " << 2;
		}
		else if(t == 3)
		{
			cout << 2 << " " << 1;
		}
	}
	else if(n == 2 && m >= 3)
	{
		for(int i=1;i<=n*m;i++)
		{
			cin >> a[i];
			if(a[i] > a[1])
			{
				t++;
			}
		}
		if(t==1 || t==2 || t==5 || t==6 || t==9 || t==10 || t==13 || t==14 || t==17 || t==18)
		{
			if(t == 1) cout << 1 << " " << 2;
			else if(t == 2) cout << 2 << " " << 2;
			else if(t == 5) cout << 3 << " " << 2;
			else if(t == 6) cout << 4 << " " << 2;
			else if(t == 9) cout << 5 << " " << 2;
			else if(t == 10) cout << 6 << " " << 2;
			else if(t == 13) cout << 7 << " " << 2;
			else if(t == 14) cout << 8 << " " << 2;
			else if(t == 17) cout << 9 << " " << 2;
			else if(t == 18) cout << 10 << " " << 2;
		}
		else
		{
			if(t == 0) cout << 1 << " " << 1;
			else if(t == 3) cout << 2 << " " << 1;
			else if(t == 4) cout << 3 << " " << 1;
			else if(t == 7) cout << 4 << " " << 1;
			else if(t == 8) cout << 5 << " " << 1;
			else if(t == 11) cout << 6 << " " << 1;
			else if(t == 12) cout << 7 << " " << 1;
			else if(t == 15) cout << 8 << " " << 1;
			else if(t == 16) cout << 9 << " " << 1;
			else if(t == 19) cout << 10 << " " << 1;
		}
	}
	else if(m == 2 && n >= 3)
	{
		for(int i=1;i<=n*m;i++)
		{
			cin >> a[i];
			if(a[i] > a[1])
			{
				t++;
			}
		}
		if(t==1 || t==2 || t==3 || t==4 || t==5 || t==6 || t==7 || t==8 || t==9 || t==0)
		{
			if(t == 0) cout << 1 << " " << 1;
			else if(t == 1) cout << 1 << " " << 2;
			else if(t == 2) cout << 1 << " " << 3;
			else if(t == 3) cout << 1 << " " << 4;
			else if(t == 4) cout << 1 << " " << 5;
			else if(t == 5) cout << 1 << " " << 6;
			else if(t == 6) cout << 1 << " " << 7;
			else if(t == 7) cout << 1 << " " << 8;
			else if(t == 8) cout << 1 << " " << 9;
			else if(t == 9) cout << 1 << " " << 10;
		}
		else
		{
			if(t == 10) cout << 2 << " " << 10;
			else if(t == 11) cout << 2 << " " << 9;
			else if(t == 12) cout << 2 << " " << 8;
			else if(t == 13) cout << 2 << " " << 7;
			else if(t == 14) cout << 2 << " " << 6;
			else if(t == 15) cout << 2 << " " << 5;
			else if(t == 16) cout << 2 << " " << 4;
			else if(t == 17) cout << 2 << " " << 3;
			else if(t == 18) cout << 2 << " " << 2;
			else if(t == 19) cout << 2 << " " << 1;
		}
	}
	else if(n >= 3 && m >= 3)
	{
		for(int i=1;i<=n*m;i++)
		{
			cin >> a[i];
			if(a[i] > a[1])
			{
				t++;
			}
		}
	}
	return 0;
}
