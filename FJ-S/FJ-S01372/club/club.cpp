#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int a[N];
int s[N];
int d[N];
int main () 
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin >> t;
	for(int i = 0;i < t; ++i)
	{
		int ans = 0;
		int n;
		cin >> n;
		int mid = n / 2;
		for(int j = 0;j < n; ++j)
		{
			cin >> a[j] >> s[j] >> d[j];
		}
		sort(a,a + 3);
		sort(s,s + 3);
		sort(d,d + 3);
		if(n == 2)
		{
			ans += a[2] + s[2] + d[2];
		}
		else
		{
			ans += a[2] + s[2] + d[2];
			mid--;
			n -= 3;
			for(int j = 0,k = 0,l = 0;j < 2 || k < 2 || l < 2;)
			{
				if(mid == 0 || n == 0)
				{
					break;
				}
				ans += max(a[j],max(s[k],d[l]));
				n--;
				if(max(a[j],max(s[k],d[l])) == a[j])
				{
					j++;
				}	
				if(max(a[j],max(s[k],d[l])) == s[k])
				{
					k++;
				}
				if(max(a[j],max(s[k],d[l])) == d[l])
				{
					j++;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
