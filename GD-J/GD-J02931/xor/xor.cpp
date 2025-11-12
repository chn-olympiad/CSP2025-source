#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAX_N = 5e5;
ll a[MAX_N + 200];
ll n,k,ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	fill(a, a + MAX_N + 201, -1);
	for(int i = 1; i <= n; ++i){
		cin >> a[i];
	}
	for(int i = 2; i <= n; ++i){
		a[i] = (a[i] xor a[i-1]);
	}
	queue<ll> q;
	ll lastqj = 0;
	ll qjh = a[1];
	q.push(a[1]);
	for(int i = 2; i <= n; ++i){
		ll op = q.front();
		if(qjh == k){
			ans++;
			qjh = a[i];
			op = a[i];
			lastqj = q.back();
			while(!q.empty()){
				q.pop();
			}
			q.push(a[i]);
		} else {
			if(abs( ( (qjh xor a[i]) xor op) - k) <= abs( ( (qjh xor a[i]) xor lastqj) - k)){
				lastqj = op;
				q.pop();
				op = q.front();
				q.push(a[i]);
				qjh = ( (qjh xor a[i]) xor lastqj);
			} else {
				q.push(a[i]);
				qjh = ( (qjh xor a[i]) xor lastqj);
			}
		}
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
