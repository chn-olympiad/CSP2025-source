#include<bits/stdc++.h>
#define up(i, a, b) for(int i = (int)a; i <= (int)b; ++i)
#define dn(i, a, b) for(int i = (int)a; i >= (int)b; --i)

using namespace std;

const int MN = 1e5 + 5;

int n;

struct node{
	int x, y, z;
	int mx, md;
}a[MN];

bool cmp(node p1, node p2){
	return (p1.mx - p1.md) < (p2.mx - p2.md);
}

void solve(){
	scanf("%d", &n);
	up(i, 1, n){
		scanf("%d%d%d", &a[i].x, &a[i].y, &a[i].z);
		int mx = max(max(a[i].x, a[i].y), a[i].z);
		int mi = min(min(a[i].x, a[i].y), a[i].z);
		int md = a[i].x + a[i].y + a[i].z - mx - mi;
		a[i].md = md, a[i].mx = mx;
	}
	sort(a + 1, a + 1 + n, cmp);
	int s1 = 0, s2 = 0, s3 = 0, ans = 0;
	dn(i, n, 1){
		if(a[i].mx == a[i].x){
			if(s1 == n / 2) ans += a[i].md;
			else s1++, ans += a[i].mx;
		}
		else if(a[i].mx == a[i].y){
			if(s2 == n / 2) ans += a[i].md;
			else s2++, ans += a[i].mx;
		}
		else{
			if(s3 == n / 2) ans += a[i].md;
			else s3++, ans += a[i].mx;
		}
	}
	printf("%d\n", ans);
}

int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T; cin >> T;
	while(T--) solve();

	return 0;
}
