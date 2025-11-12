#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

long long n, m;
long long r_score;
vector<long long> stu;
long long seats[15][15];
int fg = 0;
long long _index;
long long x, y;

bool cmp (long long prev, long long next) {
	return prev > next;
}

int main () {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for (int i = 0; i < n * m; i++) {
		long long k;
		cin >> k;
		stu.push_back(k);
	}
	r_score = stu[0];
	sort(stu.begin(), stu.end(), cmp);
	for (int i = 0; i < n * m; i++) {
		if (stu[i]==r_score) {
			_index = i + 1;
			break;
		}
	}
	x=_index / n;
	long long k;
	k=_index - x * n;
	if (k > 0) x++;
	if (k == 0)
		cout<< x << " " << n << "\n";
	else if (x % 2 == 1)
		cout << x << " " << k;
	else
		cout << x << " " << n - k + 1;
	return 0;
}
