#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
ull change(string s)
{
	ull res = 0;
	for(int i = 0 ; i < s.size() ; i++)
	{
		res = res * 122 + s[i];
	}
	return res;
}
ull t1[200001] , t2[200001] , t3[200001];
ull qp(ull x , ull y)
{
	if(y == 0)return 1;
	ull t = qp(x , y / 2);
	if(y % 2 == 0)return t * t;
	return t * t * x;
}
char s[10000001];
int main()
{
	freopen("replace.in" , "r" , stdin);
	freopen("replace.out" , "w" , stdout);
	int n , q;
	cin >> n >> q;
	for(int i = 1 ; i <= n ; i++)
	{
		scanf("%s" , s);
		t1[i] = change(s);
		scanf("%s" , s);
		t2[i] = change(s);
		t3[i] = t1[i] - t2[i];
	}
	sort(t3 + 1 , t3 + n + 1);
	for(int i = 1 ; i <= q ; i++)
	{
		scanf("%s" , s);
		ull q1 = change(s);
		scanf("%s" , s);
		ull q2 = change(s);
		ull q3 = q1 - q2;
		int ans = 0;
		for(int j = 1 ; j <= n ; j++)
		{
			if(q3 * qp(t3[j] , (ull)(0) - (ull)(2)) == 0)ans++;
		}
		cout << ans << endl;
	}
	return 0;
}
