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
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	srand(time(NULL));
	cout << rand() % 99999900; 
	return 0;
}

/*
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
