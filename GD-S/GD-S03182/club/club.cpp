#include<bits/stdc++.h>
#define pb(a) push_back(a)
#define fir first
#define sec second
using namespace std;
using ll = long long;
using pii = pair<ll,int>;
const int N = 1e5 + 5,C = 5;
int n;
pii data[N];
vector<int> v[C];
struct sat{
	pii p[C];
}arr[N];
inline ll read(){
	ll x = 0;char c = getchar();
	while(c < '0' || c > '9'){
		c = getchar();
	}
	while(c >= '0' && c <= '9'){
		x = (x<<1) + (x<<3) + (c^48);
		c = getchar();
	}
	return x;
}
inline bool cmp(pii a,pii b){
	return a.fir < b.fir;
}
void solve(){
	n = read();
	ll ans = 0;
	v[1].clear();
	v[2].clear();
	v[3].clear();
	for(int i = 1; i <= n; ++i){
		arr[i].p[1] = {read(),1};
		arr[i].p[2] = {read(),2};
		arr[i].p[3] = {read(),3};
		sort(arr[i].p + 1,arr[i].p + 1 + 3,greater<pii>());
		
		v[arr[i].p[1].sec].pb(i);
		ans += arr[i].p[1].fir;
	}
	n >>= 1;
	for(int i = 1,len; i <= 3; ++i){
		len = v[i].size();
		if(len > n){
			int tp = 0;
			for(int j = 0,id; j < len; ++j){
				id = v[i][j];
				data[++tp] = {arr[id].p[1].fir - arr[id].p[2].fir,arr[id].p[1].sec};
				data[++tp] = {arr[id].p[2].fir - arr[id].p[3].fir,arr[id].p[2].sec};
			}
			sort(data + 1,data + 1 + tp,cmp);
			for(int j = 1; j <= tp && len > n; ++j){
				if(data[j].sec == i){
					ans -= data[j].fir;
					--len;
				}
			}
		}
	}
	printf("%lld\n",ans);
	return ;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int _ = read();
	while(_--){
		solve();
	}
	return 0;
} 
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
