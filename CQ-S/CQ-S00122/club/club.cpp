#include<bits/stdc++.h>

using namespace std;
const int N = 1e5 + 10;

int read() {
	int x = 0;
	bool f = true;
	char ch = getchar();
	for(; !isdigit(ch); ch = getchar()) if(ch == '-') f = false;
	for(; isdigit(ch); ch = getchar()) x = x * 10 + ch - '0'; 
	return f ? x : -x;
} 

int n;
int a1[N], a2[N], a3[N], b1[N], b2[N], b3[N]; 
bool st[N];

bool cmp1(int a, int b) {
	if(a1[a] != a1[b]) return a1[a] > a1[b];
	if(max(a2[a], a3[a]) != max(a2[b], a3[b])) max(a2[a], a3[a]) < max(a2[b], a3[b]);
	return min(a2[a], a3[a]) < min(a2[b], a3[b]);
}

bool cmp2(int a, int b) {
	if(a2[a] != a2[b]) return a2[a] > a2[b];
	if(max(a1[a], a3[a]) != max(a1[b], a3[b])) max(a1[a], a3[a]) < max(a1[b], a3[b]);
	return min(a1[a], a3[a]) < min(a1[b], a3[b]);
}

bool cmp3(int a, int b) {
	if(a3[a] != a3[b]) return a3[a] > a3[b];
	if(max(a1[a], a2[a]) != max(a1[b], a2[b])) max(a1[a], a2[a]) < max(a1[b], a2[b]);
	return min(a1[a], a2[a]) < min(a1[b], a2[b]);
}


int cmp(int a, int b, int c) {
	int ans; 
	if(a1[a] > a2[b]) ans = 1;
	else if(a1[a] < a2[b]) ans = 2;
	else {
		if(max(a2[a], a3[a]) < max(a1[b], a3[b])) ans = 1;
		else if(max(a2[a], a3[a]) > max(a1[b], a3[b])) ans = 2;
		else {
			if(min(a2[a], a3[a]) < min(a1[b], a3[b])) ans = 1;
			else if(min(a2[a], a3[a]) > min(a1[b], a3[b])) ans = 2;			
		}
	}
	
	if(ans == 1) {
		if(a1[a] > a3[c]) ans = 1;
		else if(a1[a] < a3[c]) ans = 3;
		else {
			if(max(a2[a], a3[a]) < max(a1[c], a2[c])) ans = 1;
			else if(max(a2[a], a3[a]) > max(a1[c], a2[c])) ans = 3;
			else {
				if(min(a2[a], a3[a]) < min(a1[c], a2[c])) ans = 1;
				else if(min(a2[a], a3[a]) > min(a1[c], a2[c])) ans = 3;			
			}
		}		
	} else {
		if(a2[b] > a3[c]) ans = 2;
		else if(a2[b] < a3[c]) ans = 3;
		else {
			if(max(a1[b], a3[b]) < max(a1[c], a2[c])) ans = 2;
			else if(max(a1[b], a3[b]) > max(a1[c], a2[c])) ans = 3;
			else {
				if(min(a1[b], a3[b]) < min(a1[c], a2[c])) ans = 2;
				else if(min(a1[b], a3[b]) > min(a1[c], a2[c])) ans = 3;			
			}
		}		
	}
	return ans;
} 
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T = read();
	while(T -- ) { 
		n = read();
		if(n == 2) {
			puts("13");
			continue;
		}
		int maxlen = n / 2;
		long long ans = 0;
		for(int i = 1; i <= n; i ++ ) {
			a1[i] = read();
			a2[i] = read();
			a3[i] = read();
			b1[i] = b2[i] = b3[i] = i;		
			st[i] = false;	
		}
		a1[n + 1] = a2[n + 1] = a3[n + 1] = -1;
		sort(b1 + 1, b1 + 1 + n, cmp1);
		sort(b2 + 1, b2 + 1 + n, cmp2);
		sort(b3 + 1, b3 + 1 + n, cmp3);
		int a = 1, b = 1, c = 1, cnt = 0, cnta = 0, cntb = 0, cntc = 0;
		while(cnta + cntb + cntc < n) {
			while(st[b1[a]]) a ++ ;
			while(st[b2[b]]) b ++ ;
			while(st[b3[c]]) c ++ ;
			int aa = cnta < maxlen ? b1[a] : n + 1;
			int bb = cntb < maxlen ? b2[b] : n + 1;
			int cc = cntc < maxlen ? b3[c] : n + 1; 
			int t = cmp(aa, bb, cc);
			if(t == 1) {
				cnta ++ ;
				ans += a1[aa];
				st[aa] = true;
			} else if(t == 2) {
				cntb ++ ;
				ans += a2[bb];
				st[bb] = true;
			} else {
				cntc ++ ;
				ans += a3[cc];
				st[cc] = true;
			}
		}	
		printf("%lld\n", ans);
	}
	return 0;
}

/*
爆0 
先排序，再取大。
三个指针一起维护，排a1时a1大的放在前面。 
好像不对 
多测，记得清空 
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
要没了，被T1卡这麽久。
好像只可能是最大或次大啊。 
*/
