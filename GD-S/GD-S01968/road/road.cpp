#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long
const int MAXN = 1e4 + 5;
const int MAXK = 12;
int n , m , k , c[MAXK];
ll ans , sum , cnt[MAXK];
bool boo[MAXN] = {};
struct node{int u , v , w;};
vector <node> V;
bool cmp(node pre , node nxt){return pre.w < nxt.w;}
bool check(){
	for(int i = 1 ; i <= n ; i++)
		if(boo[i] == 0)
			return 0;
	return 1;
}
int main(){
	freopen("road.in" , "r" , stdin);
	freopen("road.out" , "w" , stdout);
	cin >> n >> m >> k; sum = n;
	for(int i = 1 , tmpa , tmpb , tmpc ; i <= m ; i++){
		scanf("%d%d%d" , &tmpa , &tmpb , &tmpc);
		V.push_back({tmpa , tmpb , tmpc});
	}
	for(int i = 1 ; i <= k ; i++){
		scanf("%d" , &c[i]);
		for(int j = 1 , tmp ; j <= n ; j++){
			scanf("%d" , &tmp);
			V.push_back({i + n , j , tmp + c[i]});
		}
	}
	sort(V.begin() , V.end() , cmp);
	for(auto now : V){
		if(boo[now.u] && boo[now.v]) continue;
		ans += now.w;
		if(now.u <= n) boo[now.u] = 1;
		boo[now.v] = 1;
		if(now.u > n){
			cnt[now.u - n]++;
			if(cnt[now.u - n] <= 1) continue;
		}
		sum--;
		if(sum == 1) break;
	}
	for(int i = 1 ; i <= k ; i++){
		if(cnt[i] > 1) ans -= (cnt[i] - 1) * c[i];
	}
	cout << ans;
	return 0;
}
