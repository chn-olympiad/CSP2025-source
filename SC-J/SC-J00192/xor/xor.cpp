#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5,maxnum = 5e6;
struct node {
	int l,r;
};
int n,k;
int a[maxn + 5];
int sum[maxn + 5];
node seq[maxn + 5];
int len = 0;
int book[maxnum + 5];
bool comp(const node& x,const node& y) {
	return x.r < y.r;
}
int ans = 0;
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d %d",&n,&k);
	for (int i = 1;i <= n;i ++) scanf("%d",&a[i]);
	for (int i = n;i >= 1;i --) sum[i] = sum[i + 1] ^ a[i];
	for (int i = n;i >= 1;i --) {
		int val = sum[i] ^ k;
		int pos = book[val];
		if (pos != 0) seq[++ len] = (node){i,pos - 1};
		else if (sum[i] == k) seq[++ len] = (node){i,n};
		book[sum[i]] = i;
	}
	sort(seq + 1,seq + len + 1,comp);
	int last = 0;
	for (int i = 1;i <= len;i ++) {
		if (seq[i].l <= last) continue;
		last = seq[i].r;
		ans ++;
	}
	printf("%d",ans);
	return 0;
}
/*
4 2
2 1 0 3
4 0
2 1 0 3

*/