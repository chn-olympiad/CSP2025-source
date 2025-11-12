#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
long long n , k , sum = 0 , ans = 0;
long long a[N];
long long b[N];
long long lssjl = 0;
struct xzqj{
	long long kaishi;
	long long jieshu;
}c[N];
bool cmp(xzqj lssx , xzqj lssy)
{
	if(lssx.jieshu != lssy.jieshu)return lssx.jieshu < lssy.jieshu;
	else lssx.kaishi < lssy.kaishi;
}
int main() {
	freopen("xor.in" , "r" , stdin);
	freopen("xor.out" , "w" , stdout);
	cin >> n >> k;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
		b[i] = b[i - 1] ^ a[i];
	}
	for(int i = 1;i <= n;i++)
	{
		for(int j = 0;j < i;j++)
		{
			if(int(b[i] ^ b[j]) == k)
			{
				//cout << i << " " << j << endl;
				sum ++;
				c[sum].kaishi = j + 1;
				c[sum].jieshu = i;
			}
		}
	}sort(c + 1 , c + 1 + sum , cmp);
	for(int i = 1;i <= sum;i++)
	{
		if(c[i].kaishi > lssjl)
		{
			ans ++;
			lssjl = c[i].jieshu;
		}
	}cout << ans << "\n";
//	for(int i = 1;i <= n;i++)
//	{
//		cout << b[i] << " ";
//	}cout << "\n";
//	for(int i = 1;i <= sum;i++)
//	{
//		cout << c[i].kaishi << " " << c[i].jieshu << "\n";
//	}
	return 0;
}
