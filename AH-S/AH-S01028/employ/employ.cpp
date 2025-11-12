#include <bits/stdc++.h>
using namespace std;

int c[25], d[25], ans;
char s[25];

int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	int n, m;
	scanf("%d%d", &n, &m);
	scanf("%s", s+1);
	for(int i = 1; i <= n; i ++){
		scanf("%d", &c[i]);
		d[i] = i;
	}
	do{
		//pp ++;
		int cnt = 0;
		for(int i = 1; i <= n; i ++){
			if(cnt >= c[d[i]] || s[i] == '0') cnt ++;
		}
		if((n - cnt) >= m) ans ++; 
	}while(next_permutation(d+1, d+1+n));
	printf("%d", ans);
	return 0;
}
