#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
const int N = 100005;
struct Subject{int Lv, d;}; 
struct Stu {
	Subject Sj[3];
	bool operator< (const Stu &t) const {
		return (Sj[0].Lv - Sj[1].Lv) > t.Sj[0].Lv - t.Sj[1].Lv; 
	}
}Stus[N];
bool cmp(Subject x, Subject y) {return x.Lv > y.Lv;} 
void solve() {
	int n; scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		scanf("%d%d%d", &Stus[i].Sj[0].Lv, &Stus[i].Sj[1].Lv, &Stus[i].Sj[2].Lv);
		for(int j = 0; j < 3; ++j) Stus[i].Sj[j].d = j;
		std::sort(Stus[i].Sj, Stus[i].Sj + 3, cmp);
//		for(int j = 0; j < 3; ++j) 
//			printf("%d ", Stus[i].Sj[j].d);
//		printf("\n\n");
	} std::sort(Stus + 1, Stus + n + 1);
	int nums[3] = {0}, ans = 0;
	for(int i = 1; i <= n; ++i) {
//		printf("Students %d %d %d\n", )
		if(nums[Stus[i].Sj[0].d] == n / 2) {
			ans += Stus[i].Sj[1].Lv;
		}
		else {
			ans += Stus[i].Sj[0].Lv;
			nums[Stus[i].Sj[0].d]++;
		}
	} printf("%d\n", ans);
}
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out","w",stdout);
	int t; scanf("%d", &t);
	while(t--)
		solve();
	return 0;
}
/*
4
4 2 1
3 2 4
5 3 4
3 5 1

4
0 1 0
0 1 0
0 2 0
0 2 0
*/ 