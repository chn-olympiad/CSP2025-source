#include <bits/stdc++.h>
using namespace std;
int a[500010];
void qwer()
{
	for(int i = 1;i <= n;i++)
	{
		if(a[i] != 1)
		{
			return;
		}
	}
	if(n % 2)
	{
		cout << 1;
		return;
	}
	else
	{
		cout << 0;
		return;
	}
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin >> n >> k;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	qwer();
	int l = 1,r = 1,num = 0;
	while(l <= r && r <= n)
	{
		int cheng = a[l];
		while(r <= n)
		{
			cheng ^= a[r];
			if(cheng == k)
			{
				num ++;
				cheng = 1;
			}
			r++;
		}
		l++;
		r = l + 0;
	}
	cout << num;
	
	return 0;
}
