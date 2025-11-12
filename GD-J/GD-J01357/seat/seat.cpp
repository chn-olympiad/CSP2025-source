#include<bits/stdc++.h>

using namespace std;
struct student
{
	int value;
	bool is_r = false;
}scr[105];
int cmp(student x, student y)
{
	return x.value>y.value;
}
int ans_p, ans_l, ans_c, n, m;
int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n*m; i++)
	{
		if(i==1)
		{
			scr[i].is_r = true;
		}
		cin >> scr[i].value;
	}
	sort(scr+1, scr+n*m+1, cmp);
	for(int i = 1; i <= n*m; i++)
	{
		if(scr[i].is_r==true)
		{
			ans_p = i;
			break;
		}
	}
	ans_c = ceil((double)ans_p/n/1.0);
	if(ans_c%2==0)
	{
		if(ans_p%n==0)
		{
			ans_l = 1;
		}
		else
		{
			ans_l = n-ans_p%n+1;
		}
	}
	else
	{
		if(ans_p%n==0)
		{
			ans_l = n;
		}
		else
		{
			ans_l = 1+ans_p%n-1;
		}
	}
	cout << ans_c << " " << ans_l;
	
	return 0;
}
