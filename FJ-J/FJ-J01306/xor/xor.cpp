#include<bits/stdc++.h>
using namespace std;

const int N = 5e5 + 10;

int n, k;
int a[N], s[N];
int ans;

inline int read(){
	int x = 0, f = 1;
	char ch = getchar();
	while(ch < '0' || '9' < ch){
		if(ch == '-') f = -1;
		ch = getchar();
	}
	while('0' <= ch && ch <= '9'){
		x = (x << 1) + (x << 3) + ch - '0';
		ch = getchar();
	}
	
	return f * x;
}

void solve(){
	ans = 0;
	n = read(), k = read();
	for(int i = 1; i <= n; ++i) a[i] = read();
	
	for(int i = 1; i <= n; ++i) s[i] = s[i - 1] ^ a[i];
//	for(int i = 1; i <= n; ++i) printf("%d ", s[i]); printf("\n");
	
	int lst = 1;
	for(int r = 1; r <= n; ++r){
		for(int l = lst; l <= r; ++l){
			if((s[r] ^ s[l - 1]) == k){
//				printf("(%d,%d)\n", l, r);
				ans++;
				lst = r + 1;
				break;
			}
		}
	}
	printf("%d\n", ans);
}

int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	solve();
	return 0;
}


/*
ai ^ k
<==>
Òì»òºÍÎª0 
*/
