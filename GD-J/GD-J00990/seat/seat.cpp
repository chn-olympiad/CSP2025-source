#include <bits/stdc++.h>
using namespace std;

int n,m;
struct score
{
	int id,val;
} a[105];

bool cmp(score x,score y)
{
	return x.val > y.val;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);	
	
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n * m;i++)
	{
		cin >> a[i].val;
		a[i].id = i;
	}
	sort(a + 1,a + (n * m) + 1,cmp);
	
	int h = 1,l = 1,idx = 1;
	while(l <= m)
	{
		if(a[idx].id == 1)
		{
			cout << l << ' ' << h;
			return 0;
		}
		
		if(l % 2 == 1)
		{
			if(h < n)
				h++,idx++;
			else if(h == n)
				l++,idx++;
		}
		else
		{
			if(h > 1)
				h--,idx++;
			else if(h == 1)
				l++,idx++;
		}
	}
	return 0;
}
