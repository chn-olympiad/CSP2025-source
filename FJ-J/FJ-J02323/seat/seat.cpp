#include <bits/stdc++.h>
using namespace std;
int n,m,a[105];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i = 1; i <= n*m; i++)
	{
		cin >> a[i];
	}
	int p = a[1],k=0;
	sort(a+1,a+n*m+1,cmp);
	for(int i = 1; i <= n*m; i++)
	{
		if(a[i]==p)
		{
			k = i;
			break;
		}
	}
	int f,l;
	if(n>0)
	{
		f = (k+n-1) / n;
	    l = k % n;
	}
    if(f%2==1)
	{
		if(l==0)
		{
			l=n;
		}
		cout << f << " " << l;
	}
	else
	{
		if(l==0)
		{
			l = 1;
		}
		cout << f << " " <<  n - l + 1;
	}
	return 0;
}
