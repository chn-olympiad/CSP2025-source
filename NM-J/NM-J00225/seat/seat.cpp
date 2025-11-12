#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
int n,m,ans;
int a[110];
bool cmp(int a,int b)
{
	return a > b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n * m;i++) cin >> a[i];
	int mark = a[1];
	sort(a + 1,a + n * m + 1,cmp);
	bool found = false;
	for(int i = 1;i <= n * m;i++)
	{
		if(a[i] == mark)
		{
			ans = i;
			break;
		}	
	}
	int x = (ans % n == 0 ? ans / n : ans / n + 1);
	int y = (ans % n == 0 ? n : ans % n);
	if(x % 2 == 0)
	{
		y = n - y + 1;
	}	
	cout << x << " " << y;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
