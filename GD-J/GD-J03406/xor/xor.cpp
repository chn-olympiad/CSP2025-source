#include <bits/stdc++.h>
using namespace std;
int a[500005];
int qianzhui[500005];
struct nodea{
	vector<int> pos;
}shuzi[5000005];
struct node{
	int l, r; 
};
vector<node> qujian;
bool cmp(node diyi, node dier){
	return diyi.r < dier.r;
}
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k;
	scanf("%d%d", &n, &k);
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
	}
	for(int i = 1; i <= n; i++){
		qianzhui[i] = (qianzhui[i - 1] ^ a[i]);	
		shuzi[qianzhui[i]].pos.push_back(i);
	} 
	for(int i = 1; i <= n; i++){
		int zhao = (k ^ qianzhui[i - 1]);
		int l = 0, r = shuzi[zhao].pos.size() - 1;
		int weizhi = -1;
		while(l <= r){
			int mid = (l + r) / 2;
			if(shuzi[zhao].pos[mid] >= i){
				weizhi = mid;
				r = mid - 1;
			}
			else{
				l = mid + 1;
			}
		}
		if(weizhi != -1){
			qujian.push_back({i, shuzi[zhao].pos[weizhi]});
		}
	}
	sort(qujian.begin(), qujian.end(), cmp);
	int lastend = -1;
	int ans = 0;
	for(int i = 0; i < qujian.size(); i++){
		if(qujian[i].l > lastend){
			ans++;
			lastend = qujian[i].r;
		}
	}
	cout << ans << endl;
}
