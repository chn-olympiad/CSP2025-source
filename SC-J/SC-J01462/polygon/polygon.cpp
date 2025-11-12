#include<cstdio>
#include<algorithm>

using namespace std;

const int N = 5005;

int n;
int mv;
long long s;

int a[N];
long long res;

int len;

int st[N];
long long t = 0;
bool cmp(const int c, const int d) {
	return c <= d;
}
void dfs(int x, int num, int start) {	 
	
	if(x == num) {	
		if(len*2 < t) res++;
		return;
	}
	
	for(int i = start;i <= n;i++) {
		int cur = a[i];
		if(cur > num) cur = num;
		for(int j = 0;j <= cur;j++) {
			if(j!=0) len = i;
			if(x+j <= n) {
				t += j*i;
				dfs(x+j, num, i+1);
				t -= j*i;
			}
			else break;
		}
	}
	return;
}
int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	scanf("%d", &n);
	for(int i = 1; i <= n;i++) {
		scanf("%d", &a[i]);
	}
	if(n < 3) printf("0");
	else if(n==3) {
		for(int i = 1;i <= n;i++) {
			if(a[i] > mv) mv = a[i];
			s += a[i];
		}
		if(s > 2*mv) printf("1");
		else printf("0");
	}
	else {
		bool flag = 1;
		for(int i = 2;i <= n;i++) {
			if(a[i] != a[i-1]) {
				flag = 0;
				break;
			}
		} 
		if(flag) {
			printf("%d", n);
		}
		else {
			sort(a+1, a+n+1, cmp);
			for(int i = 1;i <= n;i++) {
				st[a[i]]++;
			}
			for(int i = 3;i <= n;i++) {
				dfs(0, i, 1);
			}
			printf("%lld", res%998244353);
		} 
	}
	return 0;
}