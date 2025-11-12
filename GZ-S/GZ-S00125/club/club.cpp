//GZ-S00125 贵阳市南明区李端棻中学 姜铭灿 
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
using namespace std;
const int MAXN = 1e5 + 5; 
int T, n;
struct Student{
	int a[5], mx, sub;
	bool operator< (const Student& rhs) const { return a[sub] - a[mx] < rhs.a[rhs.sub] - rhs.a[rhs.mx]; }
} stu[MAXN];

int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%d", &T);
	while(T--){
		memset(stu, 0, sizeof(stu));
		int cnt[5] = {}, ans = 0;
		scanf("%d", &n);
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= 3; j++){
				scanf("%d", &stu[i].a[j]);
				if(stu[i].a[j] >= stu[i].a[stu[i].mx]) stu[i].sub = stu[i].mx, stu[i].mx = j;
				else if(stu[i].a[j] >= stu[i].a[stu[i].sub]) stu[i].sub = j;
			} 
			ans += stu[i].a[stu[i].mx], cnt[stu[i].mx]++;
		}
		int k = 0;
		for(int i = 1; i <= 3 && k == 0; i++) k = (cnt[i] > (n / 2) ? i : 0);
		if(k == 0){
			printf("%d\n", ans);
			continue;
		}
		priority_queue <Student> pq;
		for(int i = 1; i <= n; i++)
			if(stu[i].mx == k) pq.push(stu[i]);
		while(cnt[k] > n / 2) ans += -pq.top().a[pq.top().mx] + pq.top().a[pq.top().sub], pq.pop(), cnt[k]--;
		printf("%d\n", ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
