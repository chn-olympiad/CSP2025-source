#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 10121416;

struct node {
	int first,second,third;
} a[N];

bool cmp (node a, node b) {
	return a.first > b.first;
}
/*
                  ,;,,;
                 ,;;'(    马
       __      ,;;' ' \   ┇
    /'  '\'~~'~' \ /'\.)  到 
 ,;(      )    /  |.      ┇
,;' \    /-.,,(   ) \     成
     ) /       ) / )|     ┇ 
     ||        ||  \)     功
     (_\       (_\
*/
signed main () {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++) cin >> a[i].first >> a[i].second >> a[i].third;
		sort (a + 1, a + 1 + n, cmp);
		int maxnum = n / 2, sum = 0;
		for (int i = 1; i <= maxnum; i++) sum += a[i].first + a[i].second + a[i].third;
		cout << sum << '\n'; 
	}
	return 0;
}

