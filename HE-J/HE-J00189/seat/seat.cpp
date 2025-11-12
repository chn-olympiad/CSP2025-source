#include<bits/stdc++.h>
using namespace std;
#define int int32_t
#define np nullptr
#define pb emplace_back
#define all(v) v.begin(),v.end()
using ll = int64_t;
using VCI = vector<int> ;
int n, m, Rmark, cnt, y;VCI a;
inline auto cmp(int a, int b) -> bool{
	return a > b;
}signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(np);cout.tie(np);
	freopen("seat.in", "r", stdin);
	zfreopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1, tp;i<=n*m;i++){
		cin>>tp;
		a.pb(tp);
	}
	Rmark = a[0];
	sort(all(a), cmp);
	while(y <= m){
		y++;for(int i=1;i<=n;i++)
			if(a[cnt ++] == Rmark){
				cout<<y<<' '<<i<<"\n";
				return 0;
			}
		y++;for(int i=n;i>=1;i--)
			if(a[cnt ++] == Rmark){
				cout<<y<<' '<<i<<"\n";
				return 0;
			}
	}
	return 0;
}
