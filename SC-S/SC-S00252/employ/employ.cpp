#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int MAXN = 505;
const ll Mod = 998244353;
int n, m, c[MAXN], p[MAXN];
char s[MAXN];

int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	scanf("%d%d %s", &n, &m, s+1);
	for(int i = 1; i <= n; i++)	scanf("%d", c+i), p[i] = i;
	int ans = 0;
	do{
		int tmp = 0, sum = 0;
		for(int i = 1; i <= n; i++){
			if(s[i] == '0' or tmp >= c[p[i]])	++tmp;
			else								++sum;
		}
		if(sum >= m)	++ans;
	} while(next_permutation(p+1, p+1+n));
	cout<<ans;
	
	return 0;
}
/*
给定 01 序列，计算排列数，使得第 i 天前面的连续 0 段数量 <= c[p[i]]。
容易发现每个人之间是独立的。那么每个人都有若干可以选的位置。
相当于做一个二分图完美匹配问题。
我们让选择最少的人先选。然后让选择多的人后选。
应该有问题。
对，人和人之间并非独立的。因为还有人会放弃。

人的编号显然无所谓。 

想一下状压 DP 怎么写。

如果我们设 f[i][j] 表示前 i 个位置，有连续 j 个人。。。
但是怎么表征已经填了哪些人？

状压吧，孩子。 

靠，我就不该花时间在 T2 上，这下好了，写不完了。

多半去不了 WC 了，说是不要在乎，但其实还是有点可惜。。。 
*/