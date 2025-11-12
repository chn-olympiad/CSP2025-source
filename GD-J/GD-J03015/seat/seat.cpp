#include <bits/stdc++.h>
using namespace std;

int a[105];
bool cmp(int x,int y)
{
	return x > y;
}

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,r,h = 0,l = 1;
	cin >> n >> m;
	for (int i = 1;i <= n * m;i++) cin >> a[i];
	r = a[1];
	sort(a + 1,a + n * m + 1,cmp);
	for (int i = 1;i <= n * m;i++)
	{
		if (l & 1) 
		{
			if (h < n) h++;
			else l++;
		}
		else
		{
			if (h > 1) h--;
			else l++;
		}
		//cout << "//" << l << " " << h << endl;
		if (a[i] == r)
		{
			cout << l << " " << h;
			break;
		}
	}
	return 0;
}
