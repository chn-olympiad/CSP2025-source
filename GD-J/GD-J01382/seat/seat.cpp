#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[110];
bool cmp(int x,int y)
{
	return x > y;
}
int n,m;
signed main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	//int a = 1 ^ 1;
	//cout << a;
	cin >> n >> m;
	for(int i = 1;i <= n*m;i++)
	{
		cin >> a[i];
	}
	int my = a[1];
	sort(a+1,a + n*m + 1,cmp);
	int xx,yy;
	for(int i = 1;i <= n*m;i++)
	{
		//cout << my << endl;
		if(my == a[i])
		{
			//cout << i << " " << n << endl;
			xx = ((i-1)/n+1);
			int tp = ((i-1)/n+1)%2 == 1?(i-1)%n+1:m-(i-1)%n;
			cout << xx << " " <<tp;
			return 0;
		}
	}
	return 0;
 } 
