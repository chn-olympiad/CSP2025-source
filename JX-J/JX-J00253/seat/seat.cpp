#include<bits/stdc++.h>
using namespace std;
const int MAXN = 105;
struct seat{
	int id, score;
}sit[MAXN];
bool cmp(seat a, seat b){
	if(a.score == b.score) return a.id < b.id;
	return a.score > b.score;
}
int main(){
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n * m; i++){
		scanf("%d", &sit[i].score);
		sit[i].id = i;
	}
	sort(sit + 1, sit + n * m + 1, cmp);
	for(int i = 1; i <= n * m; i++){
		if(sit[i].id == 1){
			int c = i / n, r = i % n;
			if(c % 2 == 0) printf("%d %d", c + 1, r);
			else printf("%d %d", c + 1, n - r + 1);
			break;
		}
	}
    return 0;
}
