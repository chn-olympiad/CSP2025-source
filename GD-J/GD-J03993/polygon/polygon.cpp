#include<bits/stdc++.h>
using namespace std;
const int N = 5e3 + 5;
const int M = 1e8 + 5;
int n , ans = 0;
int a[N];
int b[M] , sum = 0;
void dfs(int weizhi , int shuzhi , int biaozhi)
{
	if(weizhi >= biaozhi)
	{
		sum ++;
		b[sum] = shuzhi + a[weizhi];
		sum ++;
		b[sum] = shuzhi;
		return ;
	}
	dfs(weizhi + 1 , shuzhi + a[weizhi] , biaozhi);
	dfs(weizhi + 1 , shuzhi , biaozhi);
	return ;
}
int main() {
	freopen("polygon.in" , "r" , stdin);
	freopen("polygon.out" , "w" , stdout);
	cin >> n;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}sort(a + 1 , a + 1 + n);
	for(int i = 1;i <= n;i++)
	{
		for(int j = 1;j <= sum;j++)b[j] = 0;
		sum = 0;
		if(i == 1 || i == 2)continue;
		dfs(1 , 0 , i - 1);
		for(int j = 1;j <= sum;j++)
		{
			if(b[j] > a[i])ans++;
		}
//		for(int j = 1;j <= sum;j++)
//		{
//			cout << b[j] << " ";
//		}cout << "\n";
	}cout << ans;
	return 0;
}
