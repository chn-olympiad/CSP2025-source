#include<iostream>
#include<queue>
using namespace std;

priority_queue<long long> quea, queb, quec;
long long t, n;

int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%lld", &t);
	while(t--)
	{
		scanf("%lld", &n);
		while(!quea.empty()) quea.pop();
		while(!queb.empty()) queb.pop();
		while(!quec.empty()) quec.pop();
		long long ans = 0;
		for(long long i = 1; i <= n; i++)
		{
			long long a, b, c;
			scanf("%lld%lld%lld", &a, &b, &c);
			long long maxn = max(a, max(b, c)), maxn2 = 0;
			ans += maxn;
			if(maxn == a)
			{
				maxn2 = max(b, c);
				quea.push(maxn2 - maxn);
			}
			else if(maxn == b)
			{
				maxn2 = max(a, c);
				queb.push(maxn2 - maxn);
			}
			else
			{
				maxn2 = max(a, b);
				quec.push(maxn2 - maxn);
			}
			if(quea.size() > n / 2)
			{
				ans += quea.top();
				quea.pop();
			}
			if(queb.size() > n / 2)
			{
				ans += queb.top();
				queb.pop();
			}
			if(quec.size() > n / 2)
			{
				ans += quec.top();
				quec.pop();
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
 } 
