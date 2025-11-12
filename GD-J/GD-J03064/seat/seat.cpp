#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[110],n,m,cnt;
signed main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n * m;i++)cin >> a[i],cnt += (a[i] > a[1]);
	int x = 1,y = 1;
	while(cnt)
	{
		if((y & 1) && (x == n))y++;
		else if(!(y & 1) && (x == 1))y++;
		else x += ((y & 1) ? 1 : -1);
		cnt--;
	}
	cout << x << " " << y << '\n';
	return 0;
}

