#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 5e5+10;
int n;
ll k, a[N], pre[N], sum;
int xr(ll a, ll b){
	ll sum = 0;
	ll mi = 1;
	ll aa, bb;
	while (a || b){
		if (a & 1){
			aa = 1; 
		}
		else aa = 0;
		if (b & 1){
			bb = 1;
		}
		else bb = 0;
		if (bb != aa){
			sum += mi;
		}
		mi *= 2;
		a >>= 1;
		b >>= 1;
	}
	return sum;
}
struct poli{
	int st, ed, len;
};
queue<poli> q;
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> k;
	q.push({1, n, 1});
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		if (i == 1){
			pre[i] = a[i];
		}
		else pre[i] = xr(pre[i-1], a[i]);
	}
	int geng;
	while (!q.empty()){
		geng = q.front().st;
		int st = q.front().st, ed = q.front().ed, len = q.front().len;
		//cout << "sousuo:" << st << "   ed:" << ed << "\n";
		for (int i = st; i <= ed; i++){
			int j = i + len - 1;
			if (j > ed) break;
			if (xr(pre[j], pre[i-1]) == k){
				sum++;
				//cout << "find--" << i << "-" << j << "\n"; 
				if (i - geng >= len+1){
					q.push({geng, i-1, len+1});
					//cout << "qidian:" << geng << "   zhongdian:" << i-1 << "   len:" << len+1 << "\n";  
				}
				geng = j + 1;
			}
			if (j == ed && ed - geng + 1 >= len + 1){
				//cout << j << " " << ed << " " << geng << " " << len + 1 << "\n";
				q.push({geng, ed, len+1});
				break;
				//cout << "qidian:" << geng << "   zhongdian:" << n << "   len:" << len+1 << "\n";
			}
		}
		q.pop();
	}
	cout << sum;
	
	return 0;
}
