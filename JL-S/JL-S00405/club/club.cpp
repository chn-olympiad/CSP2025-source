#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 100005;
int n, a[4][N], t;
struct node{
	int val, id, num;
	bool operator <(const node &s)const{
		return val < s.val;
	}
};
void solve(){
	vector <int> q1;
	vector <int> q2;
	vector <int> q3;
	ll ans = 0;
	scanf("%d", &n);
	int l = n / 2;
	for(int i = 1;i <= n;i++){
		scanf("%d%d%d", &a[1][i], &a[2][i], &a[3][i]);
	}
	for(int i = 1;i <= n;i++){
		if(a[1][i] >= a[2][i] && a[1][i] >= a[3][i]){
			q1.push_back(i);
		}else if(a[2][i] >= a[1][i] && a[2][i] >= a[3][i]){
			q2.push_back(i);
		}else{
			q3.push_back(i);
		}
		ans += max({a[1][i], a[2][i], a[3][i]});
	}
	if(q1.size() <= l && q2.size() <= l && q3.size() <= l){
		printf("%lld\n", ans);
		return;
	}
	if(q2.size() > l){
		swap(q1, q2);
		swap(a[1], a[2]);
	}
	if(q3.size() > l){
		swap(q1, q3);
		swap(a[1], a[3]);
	}
	if(q1.size() > n / 2){
		priority_queue <node> t;
		for(auto i : q1){
			if(a[2][i] >= a[3][i]){
				t.push({a[2][i] - a[1][i], 2, i});
			}else{
				t.push({a[3][i] - a[1][i], 3, i});
			}
		}
		while(t.size() > l){
			node p = t.top();t.pop();
			if(p.id == 2){
				ans += p.val;
				q2.push_back(p.num);
			}
			if(p.id == 3){
				ans += p.val;
				q3.push_back(p.num);
			}
		}
		if(q2.size() <= l && q3.size() <= l){
			printf("%lld\n", ans);
		}
	}
}
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%d", &t);
	while(t--){
		solve();
	}
	return 0;
}