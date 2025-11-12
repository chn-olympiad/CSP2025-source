#include<bits/stdc++.h>
using namespace std;
struct node{
	int val,id;
}a[105];
int n,m,s[15][15];
bool cmp(node x,node y)
{
	return x.val > y.val; 
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n*m;i++)
	{
		cin >> a[i].val;
		a[i].id = i;
	}
	sort(a+1,a+n*m+1,cmp);
	int x = 1,y = 1;
	for(int i = 1;i <= n*m;i++)
	{
		if(a[i].id == 1)
		{
			cout << y << " " << x;
			return 0; 
		}
		if(y % 2 == 0)
		{
			x--;
			if(x == 0)
			{
				x = 1;
				y++;
			}
		}
		else
		{
			x++;
			if(x == n+1)
			{
				x = n;
				y++;
			}
		} 
	}
	return 0;
}

