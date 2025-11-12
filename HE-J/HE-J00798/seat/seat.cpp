#include<bits/stdc++.h>
using namespace std;
struct node
{
	int x,id;
} a[110];
bool cmp(node x,node y)
{
	return x.x > y.x;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >> n >> m; 
	int k = n * m; 
	for(int i = 1;i <= k;i++)
	{
		cin >> a[i].x;
		a[i].id = i;
	}
	sort(a + 1,a + k + 1,cmp);
	int l = 1,r = 1,f = 1;
	for(int i = 1;i <= k;i++)
	{
		if(a[i].id == 1)
		{
			cout << r << " " << l;
			return 0;
		}
		l += f;
		if(f > 0)
		{
			if(l > n)
			{
				l = n;
				r++;
				f = -1;
			}
		}
		else
		{
			if(l < 1)
			{
				l = 1;
				r++;
				f = 1;
			}
		}
	}
	return 0;
}
