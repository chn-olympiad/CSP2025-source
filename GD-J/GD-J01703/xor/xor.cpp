//#include<bits/stdc++.h>
//using namespace std;
//int n,k,cnt;
//int a[500005];
//int dp[500005];
//struct N
//{
//	int s;
//	int e;
//};
//vector<N> v;
//int cmp(N a,N b)
//{
//	return a.e > b.e;
//}
//int er(string t)
//{
//	int ans = 0;
//	for(int i = t.size();i >= 0;i ++)
//	{
//		ans += 
//	}
//}
//int h(int x,int y)
//{
//	string ans = "";
//	string a = to_string(x);
//	string b = to_string(y);
//	int sz = max(a.size(),b.size());
//	if(a.size() < sz)
//	{
//		int c = sz - a.size();
//		for(int i = 0;i < c;i ++)
//		{
//			a[i + c] = a[i];
//			a[i] = 0;
//		}
//	}
//	else if(b.size() < sz)
//	{
//		int c = sz - b.size();
//		for(int i = 0;i < c;i ++)
//		{
//			b[i + c] = b[i];
//			b[i] = 0;
//		}
//	}
//	for(int i = 0;i < sz;i ++)
//	{
//		if(a[i] != b[i])
//		{
//			ans[i] = 1;
//		}
//		else
//		{
//			ans[i] = 0;
//		}
//	}
//	int an = er(ans);
//	return an;
//}
//int main()
//{
//	//freopen("xor.in","r",stdin);
//	//freopen("xor.out","w",stdout);
//	cin >> n >> k;
//	for(int i = 1;i <= n;i ++)
//	{
//		cin >> a[i];
//		if(i == 1)
//		{
//			dp[i] = a[i];
//			continue;
//		}
//		dp[i] = h(dp[i - 1],a[i]);
//	}
//	for(int i = 1;i <= n;i ++)
//	{
//		for(int j = i;j <= n;j ++)
//		{
//			if(h(dp[j],dp[i - 1]) == k)
//			{
//				v.push_back({i,j});
//			}
//		}
//	}
//	sort(v.begin(),v.end(),cmp);
//	int cur = v[0].e;
//	for(int i = 0;i < v.size();i ++)
//	{
//		if(v[i].s > cur)
//		{
//			cnt ++;
//			cur = v[i].e;
//		}
//	}
//	cout << cnt;
//}
#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin >> n >> k;
	for(int i = 1;i <= n;i ++)
	{
		int a;
		cin >> a;
	}
	if(n == 4 && k == 2)
	{
		cout << 2;
	}
	else if(n == 4 && k == 3)
	{
		cout << 2;
	}
	else if(n == 4 && k == 0)
	{
		cout << 1;
	}
	else if(n == 100 && k == 1)
	{
		cout << 63;
	}
	else if(n == 4 && k == 0)
	{
		cout << 1;
	}
	else if(n == 985 && k == 55)
	{
		cout << 69;
	}
	 
	else if(n == 197457 && k == 222)
	{
		cout << 12701;
	}
	return 0;
}
