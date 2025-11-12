// 陈健松 贵阳市第一中学 GZ-S00456

//#include<bits/extc++.h>
#include<bits/stdc++.h>


//using namespace __gnu_pbds;
// 不开ll见祖宗 
using namespace std;
#define ll long long
#define in(var) ll var; cin >> var; 
#define repeat(var,from,to) for(ll var=from;var<to;var++)
//tree<> t;
struct p{
	ll a, b, c, i;
};
p o[100005];
bool cmp1(p a, p b){
	return a.a > b.a;
}
bool cmp2(p a, p b){
	return a.b > b.b;
}
bool cmp3(p a, p b){
	return a.c > b.c;
}
int n; 
pair<int, int> getMax(int b){
	int k = -1;
	int index = -1;
	repeat(i, 0, n){
		int u;
		switch(b){
			case 0: u = o[i].a; break;
			case 1: u = o[i].b; break;
			case 2: u = o[i].c; break;
		}
		if(index == -1 || u > k){
			k = u;
			index = i;
		}
	}
	return make_pair(index, k);
}
int maxc;
ll maxAns2 = 0;
void dfs
(
int ca, int cb, int cc, ll ans, int i
){
	if(i == n) {
		maxAns2 = max(ans, maxAns2);
		return;
	}
	if(ca < maxc){
		dfs(ca + 1, cb, cc, ans + o[i].a, i + 1);
	}
	if(cb < maxc){
		dfs(ca, cb + 1, cc, ans + o[i].b, i + 1);
	}
	if(cc < maxc){
		dfs(ca, cb, cc + 1, ans + o[i].c, i + 1);
	}
}
void solve(){
	memset(o, 0, sizeof(o));
	cin >> n; 
	int teshu = 1; // 特殊性质 0: 无 1: A 2: b...
	repeat(i, 0, n){
		cin >> o[i].a;
		cin >> o[i].b;
		cin >> o[i].c;
		if(teshu == 1 && (o[i].b != 0 || o[i].c != 0)){
			teshu = 2; // 不是特殊A , 可能是特殊B 
		}
		if(teshu == 2 && o[i].c != 0){
			teshu = 0;
		}
		o[i].i = i;
	}
	maxc = n / 2;
//	cout << "maxc = " << maxc << " ts = " << teshu<<endl;
	ll ans = 0;
	auto empty = make_pair(-1, 0);
	if(teshu==1){
		// b, c = 0，直接统计A
		sort(o, o + n, cmp1);
		for(int i = 0 ; i < maxc ; i ++) {
			ans += o[i].a;
		}
	}else if(teshu==2){
		int ca = 0 , cb = 0, cc = 0;
		repeat(i, 0, n){
			auto m1 = ca >= maxc ? empty : getMax(0);
			auto m2 = cb >= maxc ? empty : getMax(1);
			auto m3 = cc >= maxc ? empty : getMax(2);
			int max1 = max(m2.second, m3.second);
			int max2 = max(m1.second, m3.second);
			pair<int, int> perfect;
			if(m1.second >= max1){
				perfect = m1;
				ans += m1.second;
				ca ++;
			}else if(m2.second >= max2){
				perfect = m2;
				ans += m2.second;
				cb ++;
			}else{
				perfect = m3;
				ans += m3.second;
				cc ++;
			}
			o[perfect.first].a = 0;
			o[perfect.first].b = 0;
			o[perfect.first].c = 0;
		}
	}else{
		maxAns2 = 0;
		dfs(0,0,0,0,0);
		ans = maxAns2;
	}
	cout << ans << endl;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	in(T);
	while(T-- > 0) solve();
	return 0;
}
