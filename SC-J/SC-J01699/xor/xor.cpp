#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 10;
int a[N],n,k;
/*
4 3
2 1 0 3

4 2 
2 1 0 3
*/
int xor_number(int l,int r)
{
	int all_cnt = 0;
	for(int i = l;i <= r;i++)
		all_cnt ^= a[i];
	return all_cnt;
}

bool check_(int l,int r)
{
	return (xor_number(l,r) == k);
}
int main()
{
	ios::sync_with_stdio(),cin.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	int ans = 0; 
	int start = 1;
	while(start <= n)
	{
		int next = -1;
		for(int lenth = 1;lenth <= n - start + 1;lenth++)
		{
			if(check_(start,start + lenth - 1) == 1)
			{
				next = lenth;
				break;
			}
		}
		if(next == -1) start = start + 1;
		else 
		{
//			cout << start << ' ' << start + next - 1 << endl;
			start = start + next,ans++; 
		}
	}
	cout << ans << endl; 
	return 0;
}