#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n;
	cin >> n;
	if(n%3==0)
	{
		cout << 3;
		return 0;
	}
	if(n%5==0)
	{
		cout << 1;
		return 0;
	}
	cout << 2;
	return 0;
}
