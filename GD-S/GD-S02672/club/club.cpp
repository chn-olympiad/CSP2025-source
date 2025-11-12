#include<bits/stdc++.h>
#define int long long
using namespace std;
int read(){
	int s = 0, f = 1;char ch = getchar();
	while(!isdigit(ch)){if(ch == '-')f = -1;ch = getchar();}
	while(isdigit(ch)){s = s * 10 + ch - '0';ch = getchar();}
	return s * f;
}
const int MAXN = 1e5 + 5;
int t, n, a[MAXN], b[MAXN], c[MAXN];
struct node{
	int id, num1, num2, op;
	bool operator < (const node &zzz)const{
		return min(num1, num2) > min(zzz.num1, zzz.num2);
	}
};
signed main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	t = read();
	while(t --){
		n = read();
		int ans = 0, ct1 = 0, ct2 = 0, ct3 = 0;
		priority_queue <node> pq;
		for(int i = 1;i <= n;i ++){
			a[i] = read(), b[i] = read(), c[i] = read();
			if(a[i] >= b[i] && a[i] >= c[i])
				ans += a[i], pq.push({i, a[i] - b[i], a[i] - c[i], 1}), ct1 ++;
			else if(b[i] >= c[i] && b[i] >= a[i])
				ans += b[i], pq.push({i, b[i] - a[i], b[i] - c[i], 2}), ct2 ++;
			else 
				ans += c[i], pq.push({i, c[i] - b[i], c[i] - a[i], 3}), ct3 ++;
		}
		int h = 0;
		if(ct1 > n / 2)h = 1;
		if(ct2 > n / 2)h = 2;
		if(ct3 > n / 2)h = 3;
		if(!h){
			printf("%lld\n", ans);
			continue;
		}
		while(!pq.empty()){
			node tmp = pq.top();
			if(tmp.op != h){
				pq.pop();
				continue;
			}
			if(ct1 > n / 2)ct1 --;
			if(ct2 > n / 2)ct2 --;
			if(ct3 > n / 2)ct3 --;
			ans -= min(tmp.num1, tmp.num2);
			pq.pop();
			if(ct1 <= n / 2 && ct2 <= n / 2 && ct3 <= n / 2)
				break;
		}
		printf("%lld\n", ans);
	}
	return 0;
} 
