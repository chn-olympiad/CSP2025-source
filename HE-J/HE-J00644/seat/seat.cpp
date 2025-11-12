#include<bits/stdc++.h>
using namespace std;
int a[110];
bool cmp(int x, int y)
{
	return x > y;
}
int main()
{

    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);	
    int n,m;
    cin>>n>>m;
    int h=n*m;
    for (int i = 1;i<=h;++i)
	{
        cin>>a[i];
    }
    int t = a[1];
    sort(a + 1, a + h + 1, cmp);
    for (int i = 1;i<=h;++i)
	{
        if (a[i] == t)
		{
        	t = i;
        	break;
		}
    }
    int x = t/n, y = t%n;
    if (y == 0)
    {
    	cout<<x<<" ";
	}
	else {
		cout<<x+1<<" ";
		x += 1;
	}
    if (x % 2 == 0)
    {
		cout<<n-y;
	}
	else
	{
		cout<<y;
	}
	fclose(stdin);
	fclose(stdout);
    return 0;
}
