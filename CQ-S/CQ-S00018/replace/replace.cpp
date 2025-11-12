#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
namespace Luo_ty{
	const int MAXN = 5000005, MAXM = 200005;
	char ch[MAXN], t1[MAXN], t2[MAXN];
	ull h[MAXN], base[MAXN], _h[MAXN], __h[MAXN];
	ull hash(int l, int r, ull *h){
		return h[r] - h[l - 1] * base[r - l + 1]; 
	}
	int l[MAXM][2], r[MAXM][2], unl[MAXM], unr[MAXM];
	ull lsh[MAXM], _;
	vector<int> id[MAXM]; 
	int main(){
		//要注意只能替换一次 
		int n, q;
		scanf("%d%d", &n, &q);
		int len = 0;
		for(int i = 1;i <= n;i++){
			scanf("%s%s", t1 + 1, t2 + 1);
			int m = strlen(t1 + 1);
			l[i][0] = len + 1;
			r[i][0] = len + m;
			for(int j = len + 1;j <= len + m;j++){
				ch[j] = t1[j - len];
			}
			len += m;
			l[i][1] = len + 1;
			r[i][1] = len + m;
			for(int j = len + 1;j <= len + m;j++){
				ch[j] = t2[j - len];
			}
			len += m;
			int itl = 1, itr = m;
			while(itl <= m && t1[itl] == t2[itl]) itl++;
			while(itr && t1[itr] == t2[itr]) itr--;
			unl[i] = itl;
			unr[i] = itr;
		}
		base[0] = 1;
		base[1] = 1145141;
		for(int i = 2;i <= 5000000;i++) base[i] = base[i - 1] * base[1];
		for(int i = 1;i <= len;i++){
			h[i] = h[i - 1] * base[1] + ch[i];
		}
		for(int i = 1;i <= n;i++){
			if(unl[i] > unr[i]) continue;
			//把前后的hash再hash一下作为等价类来划分 
			ull h1 = hash(l[i][0] + unl[i] - 1, l[i][0] + unr[i] - 1, h);
			ull h2 = hash(l[i][1] + unl[i] - 1, l[i][1] + unr[i] - 1, h);
			ull tmp = h1 * base[unr[i] - unl[i] + 1] + h2;
			lsh[i] = tmp; 
		}
		sort(lsh + 1, lsh + n + 1);
		_ = unique(lsh + 1, lsh + n + 1) - lsh - 1;
		for(int i = 1;i <= n;i++){
			if(unl[i] > unr[i]) continue;
			ull h1 = hash(l[i][0] + unl[i] - 1, l[i][0] + unr[i] - 1, h);
			ull h2 = hash(l[i][1] + unl[i] - 1, l[i][1] + unr[i] - 1, h);
			ull tmp = h1 * base[unr[i] - unl[i] + 1] + h2;
			int wz = lower_bound(lsh + 1, lsh + _ + 1, tmp) - lsh;
//			printf("%d ", wz);
			id[wz].push_back(i);
		}
//		puts("");
		for(int i = 1;i <= q;i++){
			scanf("%s%s", t1 + 1, t2 + 1);
			int m = strlen(t1 + 1), _m = strlen(t2 + 1);
			if(m != _m){
				puts("0");
				continue;
			}
			for(int i = 1;i <= m;i++){
				_h[i] = _h[i - 1] * base[1] + t1[i];
				__h[i] = __h[i - 1] * base[1] + t2[i];
			}
			int itl = 1, itr = m;
			while(itl <= m && t1[itl] == t2[itl]) itl++;
			while(itr && t1[itr] == t2[itr]) itr--;
			//看了一圈大样例，极短不等子串相同的s应该是很少的
			//所以划分一下等价类，复杂度应该有较大优化
			ull h1 = hash(itl, itr, _h);
			ull h2 = hash(itl, itr, __h);
			ull tmp = h1 * base[itr - itl + 1] + h2;
			int wz = lower_bound(lsh + 1, lsh + _ + 1, tmp) - lsh;
			if(lsh[wz] != tmp){
				puts("0");
				continue;
			}
			int cnt = 0;
			for(int j : id[wz]){
				//先看长度是否能塞进去
				if(unl[j] > itl || r[j][0] - l[j][0] + 1 - unr[j] > m - itr) continue;
				int s = itl - unl[j] + 1, len = r[j][0] - l[j][0] + 1;
				if(hash(l[j][0], r[j][0], h) == hash(s, s + len - 1, _h)) cnt++;
			}
			printf("%d\n", cnt);
		}
		//大样例过完了，只要不被刻意卡估计就过了
		//再不济也有O(nq)的50分 
//		while(1);
		return 0;
	}
}
int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	return Luo_ty::main();
}//Chelsea 2012
//182MB
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb

3 4
a b
b c
c d
aa bb
aa b
a c
b a
*/
