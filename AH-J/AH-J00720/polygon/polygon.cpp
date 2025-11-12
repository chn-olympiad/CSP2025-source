#include<bits/stdc++.h>
using namespace std;
int a[5005] , rp[5005] , num[5005];
const int mod = 998244353;
// struct node
// {
// 	int ltree , rtree , mx , sum;
// }t[4 * 1005];
// void build(int p , int l , int r)
// {
// 	if(l < r)
// 	{
// 		int mid = (l + r) >> 1;
// 		build(p * 2 , l , mid);
// 		bulid(p * 2 + 1 , mid + 1 , r);
// 	}
// 	t[p].ltree = l , t[p].rtree = r;
// 	t[p].sum = t[p * 2].sum + t[p * 2 + 1].sum;
// 	t[p].mx = max(t[p * 2].mx , t[p * 2 + 1].mx);
// 	return;
// }
int main()
{
	freopen("polygon.in" , "r" , stdin);
	freopen("polygon.out" , "w" , stdout);
	int n;
	cin >> n;
	for(int i = 1 ; i <= n ; i++)
	{
		cin >> a[i];
		rp[a[i]]++;
		if(num[a[i]] == 1)
			rp[0]++ , rp[rp[0]] = a[i];
	}
	int ans = 0;
	sort(rp + 1 , rp + rp[0] + 1);
	for(int i = 1 ; i <= n ; i++)
	{
		for(int j = i + 1 ; j <= rp[0] - 1 ; j++)
		{
			int sum = num[rp[i]] + num[rp[j]];
			for(int k = j + 1 ; k <= rp[0] && k <= sum / 2 ; k++)
			{
				int qaq = num[rp[i]] * num[rp[j]] % mod;
				ans = (ans * qaq * num[rp[k]]) % mod;
			}
		}
	}
	cout << ans;
	return 0;
}//Yin Ziqian
