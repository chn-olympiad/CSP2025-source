#include<bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f;
const int N = 5e5 + 10;
#define ll long long
#define ls id << 1
#define rs id << 1 | 1

ll n , k , cnt;
ll a[N];

pair<ll , ll> w[N]; 

struct node{
	ll l , r , sum;
}tr[N << 1];

void push_up(ll id){
	tr[id].sum = tr[ls].sum ^ tr[rs].sum;
	/*if(tr[id].sum == k){
		cnt++;;
		w[cnt].first = tr[id].l;
		w[cnt].second = tr[id].r;
	}*/
}

void build(ll id , ll l , ll r){
	tr[id].l = l , tr[id].r = r;
	tr[id].sum = 0;
	if(l == r) {
		tr[id].sum = a[l];
		/*if(tr[id].sum == k) {
			cnt++;
			w[cnt].first = l;
			w[cnt].second = r;
		}*/
		return ;
	}
	ll mid = (l + r) / 2;
	build(ls , l , mid);
	build(rs , mid + 1 , r);
	push_up(id);
}

ll sumtr(ll id , ll l , ll r){
	if(l == r) return a[l];
	if(tr[id].l == l && tr[id].r == r){
		return tr[id].sum; 
	}
	int mid = (l + r) / 2;
	return sumtr(ls , l , mid) ^ sumtr(rs , mid + 1 , r);
}

int main(){
	freopen("xor.in" , "r" , stdin);
	freopen("xor.out" , "w" , stdout);
	cin >> n >> k;
	for(ll i = 1 ; i <= n ; i++){
		scanf("%lld" , &a[i]);
	}
	build(1 , 1 , n);
	for(ll i = 1 ; i <= n ; i++){
		for(ll j = i ; j <= n ; j++){
			if(sumtr(1 , i , j) == k) {
				cnt++;
				w[cnt].first = i;
				w[cnt].second = j;
				//break;
			}
		}
	}
	sort(w + 1 , w + cnt + 1);
	ll ans = 0;
	if(cnt != 0) ans = 1;
	for(ll i = 2 , j = w[1].second ; i <= cnt ; i++){
		if(w[i].first > j){
			j = w[i].second;
			ans++;
		}
	}
	cout << ans << endl;
	return 0;
}

/*
4 3
2 1 0 3

100 1
1 0 1 1 0 0 0 1 1 1 1 1 1 0 0 1 1 1 1 1 0 0 1 1 1 0 0 1 1 1 1 0 1 0 1 1 1 0 1 1 1 1 0 1 0 0 1 1 1 0 1 1 1 0 1 0 0 1 0 1 0 1 1 1 0 1 0 1 0 1 0 1 1 1 0 1 0 1 1 0 1 1 0 1 1 1 1 0 1 1 0 1 0 1 1 0 0 0 0 1

*/
