// csp-s T1 club
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 1e5 + 5;
int a[MAXN], b[MAXN], c[MAXN];

priority_queue<pair<int, int>> pa, pb, pc;

ll ans, n;

bool cmp(int a, int b){
	return a>b;
}

void pushh(int i){
	priority_queue<pair<int, int>> tmp;
	tmp.push({a[i], 1});
	tmp.push({b[i], 2});
	tmp.push({c[i], 3});
	auto frt = tmp.top();tmp.pop();
	auto sec = tmp.top();tmp.pop();
	auto trd = tmp.top();tmp.pop();
	if (frt.second == 1){
		if (pa.size() < (n>>1) ){
			pa.push({sec.first - frt.first, i});
			ans += a[i];
		}else{
			if (pa.top().first < (sec.first - frt.first)){
				auto tp = pa.top();pa.pop();
				pa.push({sec.first - frt.first, i});
				pushh(tp.second);
				ans += a[i];
				ans -= a[tp.second];
			}else if (sec.second == 2){
				pb.push({trd.first - sec.first, i});
				ans += b[i];
			}else if (sec.second == 3){
				pc.push({trd.first - sec.first, i});
				ans += c[i];
			}
		}
	}else if (frt.second == 2){
		if (pb.size()<(n>>1)){
			pb.push({sec.first - frt.first, i});
			ans += b[i];
		}else{
			if (pb.top().first < (sec.first - frt.first)){
				auto tp = pb.top();pb.pop();
				pb.push({sec.first - frt.first, i});
				pushh(tp.second);
				ans += b[i];
				ans -= b[tp.second];
			}else if (sec.second == 1){
				ans += a[i];
				pa.push({trd.first - sec.first, i});
			}else if (sec.second == 3){
				ans += c[i];
				pc.push({trd.first - sec.first, i});
			}
		}
	}else if (frt.second == 3){
		if (pc.size()<(n>>1)){
			pc.push({sec.first - frt.first, i});
			ans += c[i];
		}else{
			if (pc.top().first < (sec.first - frt.first)){
				auto tp = pc.top();pc.pop();
				pc.push({sec.first - frt.first, i});
				pushh(tp.second);
				ans += c[i];
				ans -= c[tp.second];
			}else if (sec.second == 1){
				pa.push({trd.first - sec.first, i});
				ans += a[i];
			}else if (sec.second == 2){
				pb.push({trd.first - sec.first, i});
				ans += b[i];
			}
		}
	}
}

void solve(){
	while (pa.size())pa.pop();
	while (pb.size())pb.pop();
	while (pc.size())pc.pop();
	cin>>n;
	ans = 0;
	bool flg1= 0, flg2 = 0;
	for (int i=1;i<=n;i++){
		cin>>a[i]>>b[i]>>c[i];
	}
//	if (!(flg1 || flg2)){
//		sort (a+1, a+1+n, cmp);
//		ll ans = 0;
//		for (int i=1;i<=(n>>1);i++){
//			ans += a[i];
//		}
//		cout<<ans<<endl;
//		return ;
//	}
	
	for (int i=1;i<=n;i++){
		pushh(i);
	}
	
	cout<<ans<<endl;

	return ;
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T = 1;cin>>T;
	while (T--){
		solve();
	}
	return 0;
}

