#include <iostream>
#include <algorithm>
#define endl '\n'
using namespace std;
int n,m;
int a[105];
int r,indr;
int ansx,ansy;
bool cmp(int a,int b)
{
	return a > b;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n * m;i++)
	{
		cin >> a[i];
	}
	r = a[1];
	sort(a + 1,a + n * m + 1,cmp);
	for(int i = 1;i <= n * m;i++)
	{
		if(a[i] == r)
		{
			indr = i;
			break;
		}
	}
	ansx = (indr - 1) / n + 1;
	ansy = (indr - 1) % n + 1;
	if(!(ansx & 1)) 
	{
		ansy = n - ansy + 1;
	}
	cout << ansx << ' ' << ansy << endl; 
	return 0;
}
