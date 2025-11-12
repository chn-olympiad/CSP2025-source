#include<bits/stdc++.h>
#define qwq ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long
using namespace std;

const int N = 1e5 + 5;

struct node{
	ll w , id;
}p[N][5] , s[N];

ll t , n , to[10];

bool cmp(const node &lhs , const node &rhs){
	return lhs.w > rhs.w;
}

void solve(){
	int ans = 0;
	
	cin >> n;
	
	for(int i = 1 ; i <= n ; i ++){
		cin >> p[i][1].w >> p[i][2].w >> p[i][3].w;
		
		p[i][1].id = 1 , p[i][2].id = 2 , p[i][3].id = 3;
		
		sort(p[i] + 1 , p[i] + 4 , cmp);
		s[i] = {p[i][1].w - p[i][2].w , i};
	}
	sort(s + 1 , s + n + 1 , cmp);
	
	for(int i = 1 ; i <= n ; i ++){
		int id = s[i].id;
		
		if(to[p[id][1].id] >= n / 2) ans += p[id][2].w , to[p[id][2].id] ++;
		else ans += p[id][1].w , to[p[id][1].id] ++;
	}
	cout << ans << '\n';
}

int main(){             qwq
	freopen("club.in" , "r" , stdin);
	freopen("club.out" , "w" , stdout);
	
	cin >> t;
	
	while(t --){
		memset(to , 0 , sizeof to);
		solve();
	}
	return 0;
}
