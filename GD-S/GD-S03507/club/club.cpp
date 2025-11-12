#include<bits/stdc++.h>
#define endl '\n'
typedef long long ll;
using namespace std;

int t, n;
struct node{
	int a, b, c;
}a[100005];

int calc(node x){
	int maxn = x.a, maxid = 1;
	if(x.b > maxn){
		maxn = x.b, maxid = 2;
	}
	if(x.c > maxn){
		maxn = x.c, maxid = 3;
	}
	if(maxid == 1){
		return x.a - max(x.b, x.c);
	}else if(maxid == 2){
		return x.b - max(x.a, x.c);
	}else{
		return x.c - max(x.a, x.b);
	}
}

bool cmp(node a, node b){
	return calc(a) > calc(b);
}

void solve(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%d%d%d", &a[i].a, &a[i].b, &a[i].c);
	}
	sort(a + 1, a + n + 1, cmp);
	int cnta = 0, cntb = 0, cntc = 0;
	int ans = 0;
	for(int i = 1; i <= n; i++){
		int maxn = a[i].a, maxid = 1;
		if(a[i].b > maxn){
			maxn = a[i].b, maxid = 2;
		}
		if(a[i].c > maxn){
			maxn = a[i].c, maxid = 3;
		}
		if(maxid == 1){
			if(cnta == n / 2){
				if(a[i].b > a[i].c){
					ans += a[i].b, cntb++;
				}else{
					ans += a[i].c, cntc++;
				}
			}else{
				ans += a[i].a, cnta++;
			}
		}else if(maxid == 2){
			if(cntb == n / 2){
				if(a[i].a > a[i].c){
					ans += a[i].a, cnta++;
				}else{
					ans += a[i].c, cntc++;
				}
			}else{
				ans += a[i].b, cntb++;
			}
		}else{
			if(cntc == n / 2){
				if(a[i].a > a[i].b){
					ans += a[i].a, cnta++;
				}else{
					ans += a[i].b, cntb++; 
				}
			}else{
				ans += a[i].c, cntc++;
			}
		}
	}
	printf("%d\n", ans);
}

int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%d", &t);
	while(t--) solve();
	return 0;
}
