#include <bits/stdc++.h>
using namespace std;
const int N = 200050, M = 2500050;
const long long mo = 1599995447;
int n, m, i, j, k, l, r, ans;
char a[M], b[M];
map <long long, int> f;
int qiu(char *a, int l, int r){
	int i, s = 0;
	for(i=l; i<=r; i++){
		s = (s*29ll+a[i]-96)%mo;
	}
	return s;
}
//	int u, v, x, ra[N], rb[N], p[N];
void wwkk(){
//	for(i=1; i<=n; i++){
//		scanf("%s%s", a+1, b+1);
//		k = strlen(a+1);
//		for(j=1; j<=k; j++){
//			if(a[j] == 'b') u = j;
//			if(b[j] == 'b') v = j;
//		}
//		ra[i] = u, rb[i] = u-v, p[i] = i;
//	}
//	sort(p+1, p+n+1, [](int i, int j){
//		if(rb[i] != rb[j]) return rb[i] < rb[j];
//		return ra[i] < ra[j];
//	});
//	for(i=1; i<=m; i++){
//		scanf("%s%s", a+1, b+1);
//		if(strlen(a+1) != strlen(b+1)) puts("0");
//		else{
//			k = strlen(a+1);
//			for(j=1; j<=k; j++){
//				if(a[j] == 'b') u = j;
//				if(b[j] == 'b') v = j;
//			}
//			j = lower_bound(rb+1, rb+n+1, u-v) - rb;
//			k = upper_bound(rb+1, rb+n+1, u-v) - rb;
//			x = upper_bound(ra+j, ra+k, u) - ra - 1;
//			printf("%d\n", x-j+1);
//		}
//	}
}
int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	scanf("%d%d", &n, &m);
//	if(n > 100){
//		wwkk();
//		return 0;
//	} 
	for(i=1; i<=n; i++){
		scanf("%s%s", a+1, b+1);
		if(strcmp(a+1, b+1) == 0) continue;
		k = strlen(a+1);
		f[qiu(a, 1, k)*mo+qiu(b, 1, k)]++;
	}
	for(i=1; i<=m; i++){
		scanf("%s%s", a+1, b+1);
		if(strlen(a+1) != strlen(b+1)) puts("0");
		else{
			k = strlen(a+1), ans = 0;
			for(l=1; a[l]==b[l]; l++);
			for(r=k; a[r]==b[r]; r--);
			for(j=1; j<=l; j++){
				int s = qiu(a, j, r-1), t = qiu(b, j, r-1);
				for(k=r; b[k]; k++) s = (s*29ll+a[k]-96)%mo, t = (t*29ll+b[k]-96)%mo, ans += f[s*mo+t];
			}
			printf("%d\n", ans);
		}
	}
	return 0;
}
