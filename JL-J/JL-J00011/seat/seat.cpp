// B
// expect pts = 100
// expect diff = red

#include <bits/stdc++.h>
using namespace std;
const int maxn = 200;

int n, m;
int score[maxn];
int idx;

bool cmp(int a, int b)
{
	return a > b;
}

signed main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
    cin >> m >> n;// debug
    for(int i = 1 ; i <= n * m ; i ++)
        cin >> score[i];

	int goal = score[1];
	sort(score+1, score+1+n*m, cmp);

    for(int i = 1 ; i <= n ; i ++)
    {
        if(i % 2)
		{
			for(int j = 1 ; j <= m ; j ++)
			{
				idx ++;
				if(goal == score[idx])
					cout << i << ' ' << j << endl;
				//cout << i << ' ' << j << ' ' << idx << endl;
			}
		}
		else
		{
			for(int j = m ; j >= 1 ; j --)
			{
				idx ++;
				if(goal == score[idx])
					cout << i << ' ' << j << endl;
				//cout << i << ' ' << j << ' ' << idx << endl;
			}
		}
    }
    return 0;
}
