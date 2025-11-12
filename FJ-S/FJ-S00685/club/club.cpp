#include <bits/stdc++.h>
using namespace std;
int t;
struct student{
	int a,b,c;
	bool vis = false;
};
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while (t--)
	{
		int n,cnt = 0,cnt2 = 0,cnt3 = 0;
		student x[100005];
		cin >> n;
		int ans = 0;
		for(int i = 1;i <= n;i++)
			cin >> x[i].a >> x[i].b >> x[i].c;
		for(int i = 1;i <= n;i++)
			ans += max(max(x[i].a,x[i].b),x[i].c);
		cout << ans << endl;
	}
	return 0;
}


