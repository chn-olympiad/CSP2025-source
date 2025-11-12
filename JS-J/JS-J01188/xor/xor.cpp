#include <bits/stdc++.h>
using namespace std;
int n,k,a[500010],t,t_begin,t_end;
bool f1 = 1,f2 = 1;
struct count
{
	int ct;
	int _begin,_end;
}cnt[2100000];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
		if(a[i] != 1) f1 = 0;
		if(a[i] != 1 && a[i] != 0) f2 = 0;
		cnt[a[i]].ct = 1;
 	}
 	if(f1)
 	{
		if(k == 0) cout << n / 2;
		else if(k == 1) cout << n;
		else cout << 0;
	}
	else if(f2)
	{
		int cnt0 = 0,cnt1 = 0;
		for(int i = 1;i <= n;i++)
		{
			if(a[i] == 0) cnt0++;
			else cnt1++;
		}
		if(k == 0) cout << cnt0 + cnt1 / 2;
		else if(k == 1) cout << cnt1 + cnt0 / 2;
		else cout << 0;
	}
	return 0;
}
