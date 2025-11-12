#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	int score[110]{0};
	for(int i=1; i<= n*m; i++) cin >> score[i];
	int rs = score[1];
	sort(score+1, score+n*m+1);
	int cnt = 0;
	for(int i=n*m; i>=0; i--)
	{
		cnt++;
		if(score[i] == rs) break;
	}
	int ansm = cnt / n;
	if(cnt % n != 0) ansm++;
	int ansn = cnt % n;
	if(ansm % 2 == 0)
	{
		if(ansn == 0) ansn = 1;
		else ansn = n - ansn + 1;
	}
	else if(ansn == 0) ansn = n;
	cout << ansm << " " << ansn << endl;
	return 0;
}