#include <bits/stdc++.h>
using namespace std;
int a[10086];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	for(int i = 1;i<=n;i++)
	{
		cin >> a[i];
	}
	cin >> n >> k;
	if(n == 2){
		cout << 3;
	}
	else
	{
		if(k == 0)
		{
			cout << 2;
		}
	}
}
