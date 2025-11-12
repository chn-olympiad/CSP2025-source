#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
const int INF = 0x3f3f3f;
#define ll long long 

ll n , a[N][4] , q[4];

struct node {
	ll maxi , id , maxq;//maxi最大值 id最大值所在部门 maxq最大值与次大值之差 
}w[N];

bool cmp(node a , node b){
	if(a.id != b.id) return a.id < b.id;
	return a.maxq < b.maxq;
}

int main(){
	freopen("club.in" , "r" , stdin);
	freopen("club.out" , "w" , stdout);
	int T;
	cin >> T;
	while(T--){
		cin >> n;
		q[1] = q[2] = q[3] = 0;
		for(int i = 1 ; i <= n ; i++){
			w[i].maxi = w[i].id = w[i].maxq = 0;
			scanf("%lld%lld%lld" , &a[i][1] , &a[i][2] , &a[i][3]);
			if(a[i][1] >= a[i][2] && a[i][1] >= a[i][3]){
				w[i].maxi = a[i][1];
				w[i].id = 1 , q[1]++;
				if(a[i][2] >= a[i][3]) w[i].maxq = a[i][1] - a[i][2];
				else w[i].maxq = a[i][1] - a[i][3];
			}else if(a[i][2] >= a[i][1] && a[i][2] >= a[i][3]){
				w[i].maxi = a[i][2];
				w[i].id = 2 , q[2]++;
				if(a[i][1] >= a[i][3]) w[i].maxq = a[i][2] - a[i][1];
				else w[i].maxq = a[i][2] - a[i][3];
			}else if(a[i][3] >= a[i][1] && a[i][3] >= a[i][2]){
				w[i].maxi = a[i][3];
				w[i].id = 3 , q[3]++;
				if(a[i][1] >= a[i][2]) w[i].maxq = a[i][3] - a[i][1];
				else w[i].maxq = a[i][3] - a[i][2];
			}
		}
		ll cnt = max(q[1] , max(q[2] , q[3])) , ans = 0 , p;
		if(q[1] >= q[2] && q[1] >= q[3]) p = 1;
		else if(q[2] >= q[1] && q[2] >= q[3]) p = 2;
		else p = 3;
		if(cnt <= n / 2){
			for(int i = 1 ; i <= n ; i++){
				ans += w[i].maxi;
			}
		}else {
			sort(w + 1 , w + n + 1 , cmp);
			for(int i = 1 ; i <= n ; i++){
				ans += w[i].maxi;
			}
			if(p == 1)
				for(int i = 1 ; i <= q[1] - (n / 2) ; i++) ans -= w[i].maxq;
			else if(p == 2)
				for(int i = q[1] + 1 ; i <= q[1] + q[2] - (n / 2) ; i++) ans -= w[i].maxq;
			else 
				for(int i = q[1] + q[2] + 1 ; i <= q[1] + q[2] + q[3] - (n / 2) ; i++) ans -= w[i].maxq;
		}
		cout << ans << endl;
	} 
	return 0;
}

/*

Ren5Jie4Di4Ling5%
*/
