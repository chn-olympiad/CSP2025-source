#include<bits/stdc++.h>
using namespace std;
int a[10000];
int cnt;
int maxn = 0;
int pre[10000];
int c(int l, int r)
{
	int num = a[l];
	if(l == r) return num;
	for(int i = l + 1; i <= r; i++)
	{
		num = num ^ a[i];
	} 
	return num;
}
int main()
{
	freopen("xor.in", "r" , stdin);
	freopen("xor.out", "w", stdout);
	int n, k;
	cin >> n >> k;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	for(int i = 1; i <= n; i++)
	{
		for(int j = i; j <= n; j++)
		{
			int jl = c(i, j);
			if(jl == k)
			{
				int flag = 0;
				for(int l = i; l <= j; l++)
				{
					if(pre[l] == 1) flag = 1;;
				}
				if(flag == 1) break;
				for(int l = i; l <= j; l++)
				{
					pre[l] = 1;
				}
				cnt++;
			}
		} 
	}
	cout << cnt;
	return 0;
}
