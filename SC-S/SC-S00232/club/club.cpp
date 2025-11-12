#include <bits/stdc++.h>
#define int long long
using namespace std;
int t, n;
struct node{
	int a, b, c;
	int maxn;
}ar[100010];
bool cmp(node x, node y){
	return x.b > y.b;
}
bool cmp2(node x, node y){
	return x.b < y.b;
}
bool cmp3(node x, node y){
	return x.a > y.a;
}
bool cmp4(node x, node y){
	return x.a < y.a;
}
bool cmp5(node x, node y){
	return x.c > y.c;
}
bool cmp6(node x, node y){
	return x.c < y.c;
}

int solve(){
	int sum = 0, cnta, cntb, cntc;
	cnta = cntb = cntc = n / 2;
	for(int i = 1; i <= n; i++){
		if(ar[i].maxn == ar[i].a){
			if(cnta == 0){
				if(ar[i].b > ar[i].c && cntb != 0){
					cntb--;
					sum += ar[i].b;
				}else{
					cntc--;
					sum += ar[i].c;
				}
			}else{
				cnta--;
				sum += ar[i].a;
			}
			
		}else if(ar[i].maxn == ar[i].b){
			if(cntb == 0){
				if(ar[i].a > ar[i].c && cnta != 0){
					cnta--;
					sum += ar[i].a;
				}else{
					cntc--;
					sum += ar[i].c;
				}
			}else{
				cntb--;
				sum += ar[i].b;
			}
			
		}else if(ar[i].maxn == ar[i].c){
			if(cntc == 0){
				if(ar[i].a > ar[i].b && cnta != 0){
					cnta--;
					sum += ar[i].a;
				}else {
					cntb--;
					sum += ar[i].b;
				}
			}else{
				cntc--;
				sum += ar[i].c;
			}
			
		}
	}
	return sum;
}

signed main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%lld", &t);
	while(t--){
		for(int i = 1; i <= n; i++) ar[i].a = ar[i].b = ar[i].c = ar[i].maxn = 0;
		scanf("%lld", &n);
		for(int i = 1; i <= n; i++){
			scanf("%lld%lld%lld", &ar[i].a, &ar[i].b, &ar[i].c);
			ar[i].maxn = max(max(ar[i].a, ar[i].b), ar[i].c);
		}int nnn = solve();
		sort(ar + 1, ar + n + 1, cmp);
		int num = solve();
		sort(ar + 1, ar + n + 1, cmp2);
		int num2 = solve();
		sort(ar + 1, ar + n + 1, cmp3);
		int num3 = solve();
		sort(ar + 1, ar + n + 1, cmp4);
		int num4 = solve();
		sort(ar + 1, ar + n + 1, cmp5);
		int num5 = solve();
		sort(ar + 1, ar + n + 1, cmp6);
		int num6 = solve();
		cout << max(max(max(max(max(max(num, num2), num3), num4), num5), num6), nnn) << endl;
	}
	return 0;
}
/*
3004 4255 17336c
11894 5756 17092c
8150 14715 10991c
5149 16652 16780c
11524 11996 5433c
7690 10472 19935c
1184 6516 9246c
3231 5570 10010c
8426 16992 4654c
18955 13977 16657c

7690 10472 19935
18955 13977 16657
3004 4255 17336
11894 5756 17092
8426 16992 4654
5149 16652 16780
8150 14715 10991
11524 11996 5433
3231 5570 10010
1184 6516 9246





*/