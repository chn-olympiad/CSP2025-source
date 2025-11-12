#include<bits/stdc++.h>
using namespace std;
int a[2000000];
int n,m;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	int k = n * m;
	for(int i = 1;i <= k;i ++)
	{
		cin >> a[i];
	}
	int xr = a[1];
	int c = 1,r = 1,cnt = 0,sum = 1,cntt = 0;
	sort(a + 1,a + k + 1,cmp);
	
	for(int i = 1;i <= k;i ++){
		if (a[i] == xr)
		{
			cout << c << " " << r;
			break;
		}
		
		if (cnt == 0)
		{
			r ++;sum ++;
		}
		else if (cnt == 1){
			r --;sum ++;
		}
		else if (cnt == 2)
		{
			c ++;cnt = cntt;
		}
		
		if (sum == m)
		{
			sum = 1;
			if (cnt == 1) cntt = 0;
			else if (cnt == 0) cntt = 1;
			cnt = 2;
		}
	}
	return 0;
}
