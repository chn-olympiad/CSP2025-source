#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in", "r",stdin);
	freopen("seat.out", "w",stdout);
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	int m,n;
	cin >> n >> m;
	int paiwei[m+1][n+1];
	int lunxun = 1;
	vector<int> fenshu;
	int zhongzhuan;
	for(int b = 1;b <= n*m;b++)
	{
		cin >> zhongzhuan;	
		fenshu.push_back(zhongzhuan);
	}
	int Rfenshu = fenshu[0];
	sort(fenshu.begin(),fenshu.end());
	reverse(fenshu.begin(),fenshu.end());
	if(m % 2 == 0)
	{
		for(int i = m;i >= 1;i--)
		{
			if(lunxun == 0)
			{
				lunxun = 1;
				for(int j = n;j >= 1;j--)
				{
					if(fenshu.back() == Rfenshu)
					{
						cout << i << " " << j;
						return 0;
					}
					fenshu.pop_back();
				}
			}
			else
			{
				lunxun = 0;
				for(int k = 1;k <= n;k++)
				{
					if(fenshu.back() == Rfenshu)
					{
						cout << i << " " << k;
						return 0;
					}
					fenshu.pop_back();
				}
			}
		}
	}
	else
	{
		for(int i = m;i >= 1;i--)
		{
			if(lunxun == 1)
			{
				lunxun = 0;
				for(int j = n;j >= 1;j--)
				{
					if(fenshu.back() == Rfenshu)
					{
						cout << i << " " << j;
						return 0;
					}
					fenshu.pop_back();
				}
			}
			else
			{
				lunxun = 1;
				for(int k = 1;k <= n;k++)
				{
					if(fenshu.back() == Rfenshu)
					{
						cout << i << " " << k;
						return 0;
					}
					fenshu.pop_back();
				}
			}
		}
	}
	return 0;
}