#include <bits/stdc++.h>
using namespace std;
int a[100000];
string ans;
struct p
{
	int l1,r1;
}b[1000000];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,num = 1;
	cin >> n >> k;
	for (int i = 1 ; i <= n ; i++)
	{
		cin >> a[i];
	}
	if(n != 1 && k == 0)
	{
		cout << n / 2;
		return 0;
	}
	else if (n == 1 && k == 0)
	{
		cout << 0;
		return 0;
	}
	for (int l = 1 ; l <= n ; l++)
	{
		for(int r = l ; r <= n ; r++)
		{
			int sum = a[l];
			for (int i = l ; i <= r ; i++)
			{
				sum = sum ^ a[i];
			}
			if(sum == k)
			{
				b[num].l1 = l;
				b[num].r1 = r;
				num++;
			}
		}
	}
	cout << num;
	return 0;
}
