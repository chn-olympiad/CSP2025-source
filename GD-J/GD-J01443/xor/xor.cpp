#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 15;
using ll = long long;
ll n,k,a[N],d[N],ans,tot;
struct qq{
	ll l,r;
	friend operator <(qq x,qq y){
		return (x.r - x.l + 1) < (y.r - y.l + 1);
	}
};
bool cmp(qq x,qq y){
	return (x.r - x.l + 1) < (y.r - y.l + 1);
}
bool vis[N];
ll viss[N];
int main(){
    freopen("xor6.in","r",stdin);
//    freopen("xor.txt","w",stdout);
//    freopen("xor.in","r",stdin);
//    freopen("xor.out","w",stdout);
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k;
    for(ll i = 1,x,y;i <= n;i ++){
    	cin >> a[i];
    	d[i] = d[i - 1] ^ a[i];
	}
	priority_queue<qq> q;
	a[0] = k;
	for(int i = 1;i <= n;i ++){
		if(a[i - 1] == k && a[i] != k){
			q.push({i,i});
			viss[i] = 1;
		}
		if(a[i] == k){
			vis[i] = 1;
			viss[i] = 1;
			ans ++;
		}
	}
	while(!q.empty()){
		ll l = q.top().l,r = q.top().r;
		q.pop();
		bool g = false;
		for(int i = l;i <= r;i ++){
			if(vis[i]){
				g = true;
				break;
			}
		}
		if(g){
			continue;
		}
		if((d[l - 1] ^ d[r]) == k){
			ans ++;
			for(int i = l;i <= r;i ++){
				vis[i] = 1;
			} 
			if(r + 1 <= n){
				q.push({r + 1,r + 1});
			}
			continue;
		}
		if(r + 1 <= n){
			q.push({l,r + 1});
		}
		if(l + 1 <= r && !viss[l + 1]){
			q.push({l + 1,r});
			viss[l + 1] = 1;
		}
	}
	cout << ans;
    return 0;
}
