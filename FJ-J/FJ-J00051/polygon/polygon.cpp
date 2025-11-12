#include<cstdio>
#include<algorithm>
using namespace std;

const int MAXN = 5005;
int h[MAXN] = {};

bool cmp(int a, int b){
	return a>b;
}

int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout); 
	int n, flag = 1;
	scanf("%d", &n);
	for(int i = 1; i<=n; i++){
		scanf("%d", &h[i]);
		if(h[i] != 1) flag = 0;
	}
	sort(h+1, h+1+n, cmp);
	if(n == 3){
		if(h[3] + h[2] > h[1]) printf("1");
		else printf("0");
		return 0;
	}
	
	unsigned long long ans = 0;
	if(flag){
		for(int i = 3; i<=n; i++){
			unsigned long long w = 1;
			for(int j = 1; j<=i; j++){
				w*=(n-j+1);
				w/=j;
			}
			ans+=w;
			ans%=998244353;
		}
	}
	printf("%llu", ans);
	return 0;
}

