#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N = 2e5 + 5;

struct Str
{
	int l, ia, ib;
};

Str a[N];

signed main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n, q;
	cin >> n >> q;
	for(int i = 1; i <= n; i++)
	{
		string sa, sb;
		int tmpa, tmpb;
		cin >> sa >> sb;
		for(int i = 0; i < sa.size(); i++)
			if(sa[i] == 'b') tmpa = i + 1;
		for(int i = 0; i < sb.size(); i++)
			if(sb[i] == 'b') tmpb = i + 1;
		a[i] = {sa.size(), tmpa, tmpb};
	}
	
	while(q--)
	{
		int ans;
		string t1, t2;
		cin >> t1 >> t2;
		int l = t1.size(), ia, ib;
		
		for(int i = 0; i < t1.size(); i++)
			if(t1[i] == 'b') ia = i + 1;
		for(int i = 0; i < t2.size(); i++)
			if(t2[i] == 'b') ib = i + 1;
			
		for(int i = 1; i <= n; i++)
		{
			Str t = a[i];
			if(t.ia - t.ib == ia - ib && ia >= t.ia && l - ia >= t.l - t.ia)
				ans++;
		}
	}
	
	return 0;
}

