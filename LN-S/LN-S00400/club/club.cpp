#include <bits/stdc++.h>
#define a first

using namespace std;

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin >> T;
	while (T -- )
	{
	int n;
	cin >> n;
	pair<int,pair<int,int>> a[100010];
	for (int i = 1; i <= n; i ++ )
	{
		cin >> a[i].a >> a[i].second.first >> a[i].second.second;
		
	}
	sort(a+1, a+n+1, [](pair<int ,pair<int,int> > a,pair<int ,pair<int,int> > b){
		int aax = max({a.a,a.second.first,a.second.second});
		int aaa = (aax == a.a ? max(a.second.first,a.second.second) : (aax == a.second.first ? max(a.second.second, a.a) : max(a.a, a.second.first)));
		int bax = max({b.a,b.second.first,b.second.second});
		int baa = (bax == b.a ? max(b.second.first,b.second.second) : (bax == b.second.first ? max(b.second.second, b.a) : max(b.a, b.second.first)));
		return aax - aaa > bax - baa;
		});
	int x = 0, y= 0 ,z = 0;
	int ans = 0;
	for (int i = 1; i <= n; i ++ )
	{
		int aax = max({a[i].a,a[i].second.first,a[i].second.second});
		int aaa = (aax == a[i].a ? max(a[i].second.first,a[i].second.second) : (aax == a[i].second.first ? max(a[i].second.second, a[i].a) : max(a[i].a, a[i].second.first)));
		if (aax == a[i].a)
		{
			if (x == n/2)
			{
				ans += aaa;
				if (aaa == a[i].second.first) y ++ ;
				else if (aaa == a[i].second.second) z ++ ;
				else x ++ ;
			}
			else 
			{
				ans += aax;
				x ++ ;
			}
			
		}
		else if (aax == a[i].second.first)
		{
			if (y == n/2)
			{
				ans += aaa;
				if (aaa == a[i].second.second) z ++ ;
				else if (aaa == a[i].a) x ++ ;
				else y ++ ;
			}
			else 
			{
				ans += aax;
				y ++ ;
			}
		}
		else 
		{
			if (z == n/2)
			{
				ans += aaa;
				if (aaa == a[i].second.second) z ++ ;
				else if (aaa == a[i].a) x ++ ;
				else y ++ ;
			}
			else 
			{
				ans += aax;
				z ++ ;
			}
		}
	}
	cout << ans << endl;
}
}
