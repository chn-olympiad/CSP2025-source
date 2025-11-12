# include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int m, n;
	cin >> m >> n;
	
	int len = m * n;
	int a[len];
	
	for (int i = 1; i <= len; i++)
	    cin >> a[i];
	    
	int xiaoya = a[1];
	   
	sort(a+1, a+len+1);
	
	int num = 0;
	for (int i = 1; i <= n; i++)
	{
		if (a[i] == xiaoya)
		{
			num = len + 1 - i;
			break;
		}
    }
	
	int xiao = num / n + 1;
	int ya = num - (xiao - 1) * m;
	if (xiao % 2 == 0)
	{
		cout << xiao << " " << m + 1 - ya << '\n';
	}
	else
	{
		cout << xiao << " " << ya << "\n";
	}
	
	return 0;
}