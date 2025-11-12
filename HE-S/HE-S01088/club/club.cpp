#include<bits/stdc++.h>
using namespace std;

const int M = 1e5 + 5;
int T , n , ok[M] , cnt[3] , ans;

struct per{
	int no , cl , v;
}p[M][3];
bool operator <(per A , per B){
	return A.v < B.v;
}
priority_queue<per> pq;

int main(){
	freopen("club.in" , "r" , stdin);
	freopen("club.out" , "w" , stdout);
	ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

	cin>>T;
	while(T--){
		memset(ok , 0 , sizeof(ok));
		memset(cnt , 0 , sizeof(cnt));
		ans = 0;

		cin>>n;
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < 3; ++j){
				cin>>p[i][j].v;
				p[i][j].no = i , p[i][j].cl = j;
			}
			sort(p[i] , p[i] + 3);
			p[i][2].v -= p[i][1].v , p[i][0].v -= p[i][1].v;
			ans += p[i][1].v , p[i][1].v = 0;
			pq.push(p[i][0]) , pq.push(p[i][1]) , pq.push(p[i][2]);
		}
		while(!pq.empty()){
			auto u = pq.top(); pq.pop();
			int v = u.v , cl = u.cl , no = u.no;
			if(cnt[cl] == n / 2 || ok[no]) continue;
			ans += v , ++cnt[cl] , ok[no] = 1;
		}
		cout<<ans<<'\n';
	}

	return 0;
}
// not an easy problem
// i don't know whether my greedy is correct or not
// accept my code please!