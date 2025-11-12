#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int T, n;
struct news{
	int sty, tag;
} a[100001], b[100001], c[100001];
bool cmp(news a, news b){
	return a.sty > b.sty;
}
news choice[100001];
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	cin >> T;
	while (T--) {
		memset(choice, 0, sizeof(choice));
		scanf("%d", &n);
		for (int i=1; i<=n; i++){
			scanf("%d %d %d", &a[i].sty, &b[i].sty, &c[i].sty);
			a[i].tag = b[i].tag = c[i].tag = i;
		}
		
		sort(a+1, a+n+1, cmp);
		sort(b+1, b+n+1, cmp);
		sort(c+1, c+n+1, cmp);
		int cop[4];
		int maxn = n / 2;
		for (int i=1; i<=n; i++){
			int size1 = cop[choice[a[i].tag].tag];
			if ((a[i].sty > choice[a[i].tag].sty || choice[a[i].tag].tag == 0) && size1 < maxn) {
				choice[a[i].tag].sty = a[i].sty;
				if (cop[choice[a[i].tag].tag] > 0) 
					cop[choice[a[i].tag].tag] --;
				choice[a[i].tag].tag = 1;
				cop[1] ++;
			}
			int size2 = cop[choice[b[i].tag].tag];
			if ((b[i].sty > choice[b[i].tag].sty || choice[b[i].tag].tag == 0) && size2 < maxn) {
				choice[b[i].tag].sty = b[i].sty;
				if (cop[choice[b[i].tag].tag] > 0) 
					cop[choice[b[i].tag].tag] --;
				choice[b[i].tag].tag = 2;
				cop[2] ++;
			}
			int size3 = cop[choice[c[i].tag].tag];
			if ((c[i].sty > choice[c[i].tag].sty || choice[c[i].tag].tag == 0) && size3 < maxn) {
				choice[c[i].tag].sty = c[i].sty;
				if (cop[choice[c[i].tag].tag] > 0) 
					cop[choice[c[i].tag].tag] --;
				choice[c[i].tag].tag = 3;
				cop[3] ++;
			}
		}
		int ans = 0;
		for (int i=1; i<=n; i++){
			ans += choice[i].sty;
		}
		printf("%d\n", ans);
	}
	return 0;
}
