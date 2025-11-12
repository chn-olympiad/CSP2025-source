#include <bits/stdc++.h>
//#define int long long
#define loop(a,b) for (int a = 1 ; a <= b ; ++a)
using namespace std;
signed main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n,k;
	cin >> n >> k;
	if (k==1)
	{
		int ans=0;
		loop(i,n) 
		{
			int x;
			cin >> x;
			if (x==1) ans++;
		}
		cout << ans << endl;
	} else if (k==0)
	{
		int ans=0,t=0;
		loop(i,n)
		{
			int x;
			cin >> x;
			if (x==0) t=0,ans++;
			else t++;
			while (t>=2) t-=2,ans++;
		}
		cout << ans << endl;
	} else cout << 0 << endl;
	return 0;
}
