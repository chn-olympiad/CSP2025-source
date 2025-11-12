#include<bits/stdc++.h>
using namespace std;
int n,mx,k,t;
int a[500010];
void qwq(int r,int u)//新区间左端点是r 目前有u个区间 
{
	if(r > n)
	{
		mx = max(mx,u);
		return;
	 } 
	for(int i = r;i <= n - 1;i++)
	{
		for(int x = i;x <= n;x++)
		{
			t = a[i];
			for(int j = i + 1;j <= x;j++)
			{
				t ^= a[j];
			}
			if(t == k)
			{
				qwq(x + 1,u + 1);
			}
		}
	}
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	//ios::sync_with_stdio(false);
	cin >> n >> k;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	qwq(1,0);
	cout << mx;
	return 0;
}
