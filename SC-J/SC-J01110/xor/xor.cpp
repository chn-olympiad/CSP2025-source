#include <iostream>
using namespace std;
int n;
int k;
int a[500005];
int xo[500005];//异或“前缀和” 
int minl = 1;
int ans;
//CSPJ3CSPJ3CSPJ3CSPJ3CSPJ3CSPJ3CSPJ3CSPJ3CSPJ3CSPJ3CSPJ3CSPJ3CSPJ3CSPJ3CSPJ3CSPJ3
int qz(int nl,int nr)
{
	return (xo[nl - 1] | xo[nr]) & (~(xo[nl - 1] & xo[nr]));
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i = 1;i <= n;i ++)
	{
		cin >> a[i];
		xo[i] = (xo[i - 1] | a[i]) & (~(xo[i - 1] & a[i]));
		//cout << xo[i];
	}
	for(int r = 1;r <= n;r ++)
	{
		for (int l = r;l >= minl;l --)
		{
			if (qz(l,r) == k)
			{
				ans ++;
				minl = r + 1;
				break;
			}
		}
	}
	cout << ans;
	//cout << qz(2,3);
	return 0;
} 