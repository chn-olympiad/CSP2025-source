#include <bits/stdc++.h>
using namespace std;
int n, m, num=1, ans;
struct score
{
	int x, y;
}a[105];
bool cmp(score l, score r)
{
	return l.x>r.x;
}
int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);  cout.tie(NULL);
	
	int i, j;
	cin>>n>>m;
	for(i=1; i<=n*m; i++)
	{
		cin>>a[i].x;
		a[i].y=i;
	}
	sort(a+1, a+n*m+1, cmp);
	for(i=1; i<=n*m; i++)
	{
		if(a[i].y==1)
			ans=i;
	}
	int l, r;
	l=ans/n+1;
	r=ans-(l-1)*n;
	if(r==0)
	{
		r=n;
		l--;
	}
	if(l%2==0)
	{
		cout<<l<<" "<<(n-r+1);
	}
	else
	{
		cout<<l<<" "<<r;
	}
	return 0;
}
