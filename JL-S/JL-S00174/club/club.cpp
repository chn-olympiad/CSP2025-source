#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int a,s[N][4],d[N];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T,f;
	cin >> T;
	while(T--)
	{
		cin >> a;
		for(int i = 1 ; i <= a ; i++)
			cin >> s[i][1] >> s[i][2] >> s[i][3];
		if(a == 2)
		{
			d[1] = s[1][1] + s[2][2];
			d[2] = s[1][1] + s[2][3];
			d[3] = s[1][2] + s[2][1];
			d[4] = s[1][2] + s[2][3];
			d[5] = s[1][3] + s[2][1];
			d[6] = s[1][3] + s[2][2];
			for(int i = 1 ; i <= 6 ; i++)
				if(d[1] < d[i])
					d[1] = d[i];
			cout << d[1];
		}
		else
		{
			for(int i = 1 ; i <= a ; i++)
				for(int j = 1 ; j <= a ; j++)
					if(s[i][1] <= s[i + 1][1])
						swap(s[i][1],s[i + 1][1]);
			for(int i = 1 ; i <= a / 2 ; i++)
				f += s[i][1];
			cout << f;
		}
	}
	return 0;
}
