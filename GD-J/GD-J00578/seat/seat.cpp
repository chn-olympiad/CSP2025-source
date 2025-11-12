#include<bits/stdc++.h>
using namespace std;
int n,m,k,r,temp,calc;
int a[200];
bool cmp(int xx,int yy)
{
	return xx > yy;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	k = n * m;
	for(int i = 1;i <= k;i++)
	{
		cin >> a[i];
	}
	temp = a[1];
	sort(a + 1,a + k + 1,cmp);
	for(int i = 1;i <= k;i++)
	{
		if(a[i] == temp)
		{
			r = i;
			break;
		}
	}
	calc = r / n;
	if(calc * n == r)
	{
		if(calc % 2 == 0) cout << calc << " " << 1 << endl; 
		else cout << calc << " " << n << endl;
	}
	else if(calc % 2 == 0)
	{
		cout << calc + 1 << " " << r - (calc * n) << endl;
	}
	else
	{
		cout << calc + 1 << " " << n - r + (calc * n) + 1 << endl;
	}
	return 0;
 } 
