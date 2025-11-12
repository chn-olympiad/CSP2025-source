#include <bits/stdc++.h>
using namespace std;
#define cst const
#define sttc static
#define  FOR(i, s, e) for (int i=int(s);i<=int(e);i++)
#define _FOR(i, s, e) for (int i=int(s);i>=int(e);i--)

int n, m, cur;
vector<int> a;
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(false);

	cin>>n>>m, a.resize(n*m);
	for (auto &c:a)cin>>c;
	cur=a[0], sort(a.begin(), a.end(), [&](cst int &a, cst int &b){return a>b;});
	if (m==1)return printf("%d", find(a.begin(), a.end(), cur)-a.begin()+1), 0;
	vector<int> delta;delta.reserve(2*m);
	FOR (i, 1, m)delta.push_back(i);
	_FOR (i, m, 1)delta.push_back(i);
	sttc int i=1, j=1, p=-1;
	for (cst auto &c:a){
		(++p)%=delta.size();
		if (p==m || (!p && !(i==1 && j==1)))i++;
		j=delta[p];
		if (c==cur)return printf("%d %d", i, j), 0;
	}
	printf("You have no eggs!!!");
	return 0;
}
/*
5 3
1 9 14 15 13 12 11 10 2 3 4 5 6 7 8 

1 100
90 100 99 98 97 96 95 94 93 92 91 89 88 87 86 85 84 83 82 81 80 79 78 77 76 75 74 73 72 71 70 69 68 67 66 65 64 63 62 61 60 59 58
57 56 55 54 53 52 51 50 49 48 47 46 45 44 43 42 41 40 39 38 37 36 35 34 33 32 31 30 29 28 27 26 25 24 23 22 21 20 19 18 17 16 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1
*/