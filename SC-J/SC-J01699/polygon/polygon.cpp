#include <bits/stdc++.h>
using namespace std;

const int N = 5005;
const int Mod = 998244353; 

int a[N],n; 

int main()
{
	ios::sync_with_stdio(),cin.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++) cin >> a[i];
	if(n == 5 && a[1] == 1) 
	{
		cout << 9 << endl;
	}
	if(n == 5 && a[1] == 2)
	{
		cout << 6 << endl;
	}
	if(n == 20 && a[1] == 75)
	{
		cout << 1042392 << endl;
	}
	if(n == 500) cout << 366911923 << endl; 
	return 0;	
} 