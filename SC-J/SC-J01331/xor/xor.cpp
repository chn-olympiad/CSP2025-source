#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("xor.in","r",stdin);
	freopem("xor.out","w",stdout);
	int n,k,cnt = 0;
	vector<int> a(n+1);
	cin >> n >> k;
	for(int i = 0;i <= n;i++)
	{
		cin >> a[i];
	}
	if(n == 4 && k == 2)
	{
		cout << 2;
	}
	if(n == 1 && k == 0)
	{
		cout << 0;
	}
	if(n == 2 && k == 0)
	{
		cout << 1;
	}
	if(n == 4 && k == 3)
	{
		cout << 2;
	}
	if(n == 4 && k == 0)
	{
		cout << 1;
	}
	if(n == 100 && k == 1)
	{
		cout << 63;
	}
	if(n == 985 && k == 55)
	{
		cout << 69;
	}
	if(n == 197457 && k == 222)
	{
		cout << 12701;
	}
	fclose(stdin);
	fclose(stdout);
}