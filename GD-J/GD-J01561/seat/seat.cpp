#include<bits/stdc++.h>
using namespace std;
int n,m;
struct node
{
	int z,x;
}a[105];
int cmp(node cx,node cy)
{
	return cx.z > cy.z;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n*m;i++)
	{
		cin >> a[i].z;
		a[i].x = i;
	}
	sort(a+1,a+1+n*m,cmp);
	int num;
	for(int i = 1;i <= n*m;i++)
	{
		if(a[i].x == 1)
		{
			num = i;
			break;
		}
	}
	int cnt = num / n;
	if(num % n > 0)
		cnt++;
	int i;
	if(num == n)
		i = num;
	else
		i = num % n;
	if(cnt % 2 == 1)
		cout << cnt << ' ' << i;
	else
		cout << cnt << ' ' << n - i + 1;
	return 0;
}
