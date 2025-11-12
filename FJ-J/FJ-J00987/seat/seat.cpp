#include <iostream>
#include <cstring>
#include <algorithm>
#define endl '\n'
using namespace std;
using ll = long long;
ll n, m, ix, row, col;

struct seat{
	ll score;
	bool R;
}a[1000005];

bool cmp(seat a, seat b){
	return a.score > b.score;
}

int main(void){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for(int i=1; i<=n*m; ++i){
		cin >> a[i].score;
		if(i == 1) a[i].R = true;
		else a[i].R = false;
	}
	sort(a+1, a+n*m+1, cmp);
	for(ix=1; ix<=n*m; ++ix)
		if(a[ix].R)
			break;
	row = ix/n;
	if(ix != n) ++row;
	col = ix%n;
	if(col == 0)
		col = n;
	if(row % 2 == 0)
		col = n-col+1;
	cout << row << " " << col;
	return 0;
}

/*
11/01 8:45 T2
11/01 8:49 someone tries to use notepad to open cpp 
11/01 9:04 teacher said that we're testing "CSS"
           html test(absolutely not)
11/01 9:22 T2 finished (&checked, pass examples 2/2)
           beg for no bugs
11/01 10:55 found many bugs
11/01 10:59 fixed. 30 mins left (checked, pass examples 3/3)
exp. 100pts

[18-7-7-7 -> Splash!]

subscribe Astralyn_S plz ^-^(FJ-J00987)
*/
