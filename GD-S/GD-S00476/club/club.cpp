#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 2e5 + 10;

ll n, cnt[5];
struct PEO{
	ll val[5], maxx, id;
}A[N];
struct NODE{
	ll num, maxx1, maxx2;
	bool operator< (const NODE &node) const{
		return num > node.num;
	}
}; 

void init(){
	for(int i = 1; i <= 3; i++) cnt[i] = 0;
}

void solve(){
	init();
	scanf("%lld", &n);
	for(int i = 1; i <= n; i++){
		scanf("%lld %lld %lld", &A[i].val[1], &A[i].val[2], &A[i].val[3]);
		ll maxx = 0, id = 0;
		if(A[i].val[1] > maxx) maxx = A[i].val[1], id = 1;
		if(A[i].val[2] > maxx) maxx = A[i].val[2], id = 2;
		if(A[i].val[3] > maxx) maxx = A[i].val[3], id = 3;
		cnt[id]++, A[i].maxx = maxx, A[i].id = id;
	}
	ll maxcnt = max(cnt[1], max(cnt[2], cnt[3]));
	if(maxcnt <= n / 2){
		ll res = 0;
		for(int i = 1; i <= n; i++) res += A[i].maxx;
		printf("%lld\n", res);
		return ;
	}else{
		ll res = 0, idd = 0;
		if(maxcnt == cnt[1]) idd = 1;
		else idd = (maxcnt == cnt[2] ? 2 : 3);
		vector<NODE> peo;
		for(int i = 1; i <= n; i++){
			if(A[i].id != idd) res += A[i].maxx;
			else{
				ll maxx1 = A[i].maxx, maxx2 = 0;
				for(int j = 1; j <= 3; j++)
					if(A[i].val[j] > maxx2 && j != A[i].id) maxx2 = A[i].val[j];
				peo.push_back({maxx1 - maxx2, maxx1, maxx2});
			}
		}
		sort(peo.begin(), peo.end());
		for(int i = 0; i < (int)peo.size(); i++){
			if(i < n / 2) res += peo[i].maxx1;
			else res += peo[i].maxx2;
		}
		printf("%lld\n", res);
	}
}

int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T = 1;
	scanf("%d", &T);
	while(T--) solve();
	return 0;
}
