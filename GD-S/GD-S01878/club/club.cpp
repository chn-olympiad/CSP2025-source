#include <iostream>
#include <cstdio>
#include <cstring>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <queue>
#define int long long
#define N 100005
#define PII pair<int,int>
using namespace std;
int T,n;
struct node{
	int val,id;
}a[N][5];
int ans[5],cnt[5];
priority_queue<int>q[5];
signed main(){
	freopen("club.in","r",stdin),freopen("club.out","w",stdout);
	cin >> T;
	for (;T--;) {
		for (int i = 0;i <= 3;i ++) ans[i] = 0,cnt[i] = 0;
		for (int i = 0;i <= 3;i ++) {
			while(!q[i].empty()) q[i].pop();
		}
		scanf("%lld",&n);
		for (int i = 1;i <= n;i ++)
			for (int j = 1;j <= 3;j ++) scanf("%lld",&a[i][j].val),a[i][j].id = j;
		for (int i = 1;i <= n;i ++) {
			stable_sort(a[i] + 1,a[i] + 1 + 3,[](node x,node y) {
				if (x.val == y.val) return x.id < y.id;
				return x.val > y.val;
			});
			ans[a[i][1].id] += a[i][1].val,cnt[a[i][1].id] ++;
			q[a[i][1].id].push(a[i][2].val - a[i][1].val);
		}
		bool flag = 0;
		for (int i = 1;i <= 3;i ++) flag |= (cnt[i] > n / 2);
		if (!flag) {
			int res = 0;
			for (int i = 1;i <= 3;i ++) res += ans[i];
			printf("%lld\n",res);
			continue;
		}
		int res = 0;
		for (int i = 1;i <= 3;i ++) res += ans[i];
		int mxid = 1;
		for (int i = 2;i <= 3;i ++)
			if (cnt[i] > n / 2) {
				mxid = i;
				break;
			}
		while((int)q[mxid].size() > n / 2) {
			int t = q[mxid].top();
			q[mxid].pop();
			res += t;
		}
		printf("%lld\n",res);
	}
	return 0;
}
