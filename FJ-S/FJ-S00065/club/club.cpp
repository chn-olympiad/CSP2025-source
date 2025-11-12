#include <bits/stdc++.h>
using namespace std;

int n, s1, s2, s3, maxn, n1, n2, n3;

struct S
{
	int v1, v2, v3;
	void read()
	{
		cin >> v1 >> v2 >> v3;
	}
}a[100001];

void dfs(int step)
{
	if (step > n)
	{
		maxn = maxn = max(maxn, s1 + s2 + s3);
		return;
	}
	
	if (n1 + 1 <= n / 2)
	{
		s1 += a[step].v1;
		n1 ++;
		dfs(step + 1);
		s1 -= a[step].v1;
		n1 --;
	}

	if (n2 + 1 <= n / 2)
	{
		s2 += a[step].v2;
		n2 ++;
		dfs(step + 1);
		s2 -= a[step].v2;
		n2 --;
	}
	
	if (n3 + 1 <= n / 2)
	{
		s3 += a[step].v3;
		n3 ++;
		dfs(step + 1);
		s3 -= a[step].v3;
		n3 --;
	}
}

bool cmpA(S x, S y)
{
	return x.v1 > y.v1;
}

bool cmpB(S x, S y)
{
	return abs(x.v1 - x.v2)  > abs(y.v1 - y.v2);
}

int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	int T;
	cin >> T;
	
	while (T --)
	{
		s1 = s2 = s3 = maxn = 0;
		cin >> n;
		bool f2 = 1, f3 = 1;//用于判断特殊性质A和B  
		for (int i = 1; i <= n; i++) 
		{
			a[i].read();
			if (a[i].v2 == 1) f2 = 0;
			if (a[i].v3 == 1) f3 = 0;
		} 
		
		if (f2 && f3)//特殊性质A
		{
			//由于每个人 都对其他两个俱乐部兴趣为0 所以最大值就为 降序排列下的前n/2个数的和
			sort(a + 1, a + n + 1, cmpA);
			
			int ans = 0;
			for (int i = 1; i <= n / 2; i++)
			{
				ans += a[i].v1;
			} 
			
			cout << ans << endl;
			continue;
		} 
		
		if (f3)//特殊性质B
		{
			//由于每个人 都对第三家俱乐部兴趣为0 所以求最大值的方法 就是利用贪心 优先考虑对于 前两家俱乐部的兴趣的差值大的人 
			sort(a + 1, a + n + 1, cmpB);
			 
			int ans = 0, numof1 = 0, numof2 = 0;
			for (int i = 1; i <= n; i++)
			{
				if (a[i].v1 > a[i].v2 && numof1 + 1 <= n / 2)//如果对俱乐部1的兴趣更大 且 还有名额 
				{
			 		numof1 ++;
					ans += a[i].v1; 
					continue;
				}
				
				if (a[i].v2 > a[i].v1 && numof2 + 1 <= n / 2)//如果对俱乐部2的兴趣更大 且 还有名额 
				{
					numof2 ++;
					ans += a[i].v2; 
					continue;
				}
				
				//判断到这里 还没有被continue掉 就说明 自己更喜欢的俱乐部满了 所以哪家俱乐部 有名额 就去哪家俱乐部  
				if (numof1 + 1 <= n / 2)
				{
					numof1 ++;
					ans += a[i].v1; 
					continue;
				} 
				
				if (numof2 + 1 <= n / 2)
				{
					numof2 ++;
					ans += a[i].v2; 
					continue;
				} 
			}
			
			cout << ans << endl;
			continue;
		} 
		
		dfs(1);
		
		cout << maxn << endl;
	}
	
	return 0;
}
