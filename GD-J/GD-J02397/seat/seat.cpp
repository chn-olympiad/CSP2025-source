# include <bits/stdc++.h>
using namespace std;

int n,m,all,a1,x,cnt = 1;
int chu,yu;

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	all = n * m;
	cin >> a1;
	for (int i = 2;i <= all;i ++) {
		cin >> x;
		if (x > a1) cnt ++;
	}
	chu = cnt / n;
	yu = cnt % n;
	if (yu == 0) {
		yu = n;
		chu --;
	}
	cout << (chu + 1) << " ";
	if (chu % 2 == 0) cout << yu;
	else cout << (n+1-yu);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
