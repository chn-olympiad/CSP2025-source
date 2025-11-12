#include<bits/stdc++.h>
using namespace std;
#define int long long
int cj[500];
bool cmp(int x,int y)
{
	return x > y;
}
signed main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin >> n >> m;
	for(int i = 1;i <= n*m;i++)
	{
		cin >> cj[i];
	}
	int p = cj[1];
	sort(cj+1,cj+n*m+1,cmp);
	int pos;
	for(int i = 1;i <= n*m;i++)
	{
		if(cj[i] == p)
		{
			pos = i;
			break;
		}
	}
	int ls = (pos-1)/n+1;
	int hs = (pos-1)%n+1;
	if(ls%2 == 1)
	{
		cout << ls << ' ' << hs;
	}
	else
	{
		cout << ls << ' ' << n+1-hs;
	}
	return 0;
}
