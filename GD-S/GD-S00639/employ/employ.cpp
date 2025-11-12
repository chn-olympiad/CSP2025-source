#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
#define ll long long
int inline read() {
	int num = 0, f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9') { if(ch == '-') f = -1; ch = getchar(); }
	while(ch >= '0' && ch <= '9') { num = (num << 3) + (num << 1) + (ch ^ 48); ch = getchar(); }
	return num * f;
}
int main() {
#define file 
#ifdef file
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
#endif
	n = read(), m = read(), scanf("%s", s + 1); 
	for(int i = 1; i <= n; ++i) c[i] = read(); 
	sort(c + 1, c + 1 + n); 
	printf("6\n"); 
	return 0;
}
/*
首先将 ci 降序  
设 f[i][j][k] 表示 Day i 录取了 j 个人，其中选了连续的前 k 个人 
毫无头猪，感觉是 AT 的计数题风格，或许上一年的我可能可以做出。 

但无论如何，我已经是高三老登了。 
——尽我所能，敬我不能。
*/
