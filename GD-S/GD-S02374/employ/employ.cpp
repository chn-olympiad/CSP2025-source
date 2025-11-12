#include <bits/stdc++.h>
using namespace std;

const int p = 998244353;
int a[505];
char ch[505];

int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
	bool flag = 1;
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> ch[i];
		if(ch[i]=='0')flag = 0;
	}
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	if(flag)
	{
		sort(a+1,a+n+1);
		int cur = 0;
		for(int i = 1; i <= n; i++)
			if(a[i]==0)cur++;
		long long mul = 1;
		for(int i = cur+1; i <= n; i++){
			mul=mul*(n-cur+min(cur,a[i]))%p;
		}
		cout << mul;
	}
	return 0;
}
