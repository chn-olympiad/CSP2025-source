#include<bits/stdc++.h>
using namespace std;
int read(){
	int cnt = 0, sign = 1;
	char c = getchar();
	while(!isdigit(c)){
		if(c == '-')	sign = -1;
		c = getchar();
	}
	while(isdigit(c)){
		cnt = (cnt << 1) + (cnt << 3) + (c ^ 48);
		c = getchar();
	}
	return cnt * sign;
}
const int N = 1e5 + 10;
struct node{
	int a[5];
	int maxn, mid;
}mbr[N];
int maxid(node x){
	if(x.a[1] >= x.a[2] && x.a[1] >= x.a[3])	return 1;
	if(x.a[2] >= x.a[1] && x.a[2] >= x.a[3])	return 2;
	return 3;
}
int midid(node x){
	if((x.a[1] <= x.a[2] && x.a[1] >= x.a[3]) || (x.a[1] <= x.a[3] && x.a[1] >= x.a[2]))	return 1;
	if((x.a[2] <= x.a[1] && x.a[2] >= x.a[3]) || (x.a[2] >= x.a[1] && x.a[2] <= x.a[3]))	return 2;
	return 3;
}
bool cmp(node x, node y){
	return (x.a[x.maxn] - x.a[x.mid] == y.a[y.maxn] - y.a[y.mid]) ? (x.a[x.maxn] == y.a[y.maxn] ? (x.a[x.mid] > y.a[y.mid]) : x.a[x.maxn] > y.a[y.maxn]) : (x.a[x.maxn] - x.a[x.mid] > y.a[y.maxn] - y.a[y.mid]);
}
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T = read();
	while(T--){
		int cnt[5];
		memset(cnt, 0, sizeof(cnt));
		int n = read();
		for(int i = 1; i <= n; i++){
			int a = read(), b = read(), c = read();
			mbr[i].a[1] = a;
			mbr[i].a[2] = b;
			mbr[i].a[3] = c;
			mbr[i].maxn = maxid(mbr[i]);
			mbr[i].mid = midid(mbr[i]);
//			if(T == 1)	printf(">>>>%d %d\n", mbr[i].maxn, mbr[i].mid);
		}
		sort(mbr + 1, mbr + n + 1, cmp);
		int ans = 0;
		for(int i = 1; i <= n; i++){
//			printf(">>%d\n", cnt[mbr[i].maxn]);
			if(cnt[mbr[i].maxn] == n / 2){
				ans += mbr[i].a[mbr[i].mid];
				cnt[mbr[i].mid]++;
//				printf("AC\n");
			}
			else{
				ans += mbr[i].a[mbr[i].maxn];
				cnt[mbr[i].maxn]++;
			}
//			if(T == 1) printf(">>%d %d %d\n", cnt[1], cnt[2], cnt[3]);
		}
		printf("%d\n", ans);
	}
	return 0;
} 
