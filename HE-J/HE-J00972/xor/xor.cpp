#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int a[N];
int n,k;
int c1,c0; 
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i = 1;i <= n;i ++ )
	{
		cin >> a[i];
		if(a[i] == 1) c1 ++ ;
		if(a[i] == 0) c0 ++ ;	
	} 
	if(c1 == n && k == 0)
	{
		cout << 0;
		return 0;
	}
	else
	{
		if(k == 1)
		{
			cout << c1;
			return 0;
		}
		if(k == 0)
		{
			for(int i = 1;i <= n;i ++ )
			{
				if(a[i] == 1 && a[i + 1] == 1)
				{
					c0 ++ ;
					i += 2;
				}
			}
			cout << c0;
			return 0;
		}
	}
//	for(int i = 2;i <= n;i ++ )
//	{
//		a[i] = a[i] ^ a[i - 1];
//	}
//	cout << a[n];
	cout << 0;
	return 0;
}
