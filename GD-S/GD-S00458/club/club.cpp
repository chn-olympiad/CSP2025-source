#include<bits/stdc++.h>
using namespace std;
#define ll long long
constexpr int N = 100005;
struct Node{
	ll x , y , z;
	ll maxn , minn , midn;
}a[N];
int n;
bool cmp1(Node x , Node y){
	return x.maxn - x.midn > y.maxn - y.midn;
}
void solve(){
	cin >> n;
	for(int i = 1 ; i <= n ; i++){
		cin >> a[i].x >> a[i].y >> a[i].z;
		a[i].maxn = max(a[i].x , max(a[i].y , a[i].z));
		a[i].minn = min(a[i].x , min(a[i].y , a[i].z));
		if(a[i].x != a[i].maxn && a[i].x != a[i].minn){
			a[i].midn = a[i].x;
		}
		
		else if(a[i].y != a[i].maxn && a[i].y != a[i].minn){
			a[i].midn = a[i].y;
		}
		else{
			a[i].midn = a[i].z;
		}
	}
	sort(a + 1 , a + n + 1 , cmp1);
//	for(int i = 1 ; i <= n ; i++){
//		cout << a[i].maxn << " " << a[i].midn << " " << a[i].minn << " " << a[i].x <<  " " << a[i].y << " " << a[i].z << endl;
//	}
//	cout << endl << endl;
	int cnt1 = 0 , cnt2 = 0 , cnt3 = 0;
	ll ans = 0;
	int id = 0;
	int i = 1;
	for(; i <= n ; i++){
		ans += a[i].maxn;
		if(a[i].maxn == a[i].x){
//			cout << 1 << endl;
			cnt1++;
			if(cnt1 == 1ll* n / 2){
				id = 1;
				break;
			}
		}else if(a[i].maxn == a[i].y){
//			cout << 2 << endl;
			cnt2++;
			if(cnt2 == 1ll * n / 2){
				id = 2;
				break;
			}
		}else{
//			cout << 3 << endl;
			cnt3++;
			if(cnt3 == 1ll * n / 2){
				id = 3;
				break;
			}
		}
		
		
		
	}
	i++;
	if(i >= n){
		cout << ans << endl;
		return ;
	}
	for(int j = i;j<=n;j++){
		if(id == 1){
			if(a[j].maxn == a[j].x ){
				a[j].maxn = a[j].midn;
			}
			if(a[j].minn == a[j].x){
				a[j].minn = a[j].midn;
			}
		}
		if(id == 2){
			if(a[j].maxn == a[j].y ){
				a[j].maxn = a[j].midn;
			}
			if(a[j].minn == a[j].y){
				a[j].minn = a[j].midn;
			}
		}
		if(id == 3){
			if(a[j].maxn == a[j].z ){
				a[j].maxn = a[j].midn;
			}
			if(a[j].minn == a[j].z){
				a[j].minn = a[j].midn;
			}
		}
	}
	int id1 = 0;
	sort(a + i , a + n + 1 , cmp1);
//	for(int j = i ; j <= n ;j++){
//		cout << a[j].maxn << " " << a[j].midn << " " << a[j].minn << endl;
//	}
	for(;i<=n;i++){
		ans += a[i].maxn;
		if(a[i].maxn == a[i].x){
			cnt1++;
			if(cnt1 == 1ll* n / 2){
				id1 = 1;
				break;
			}
		}else if(a[i].maxn == a[i].y){
			cnt2++;
			if(cnt2 == 1ll * n / 2){
				id1 = 2;
				break;
			}
		}else{
			cnt3++;
			if(cnt3 == 1ll * n / 2){
				id1 = 3;
				break;
			}
		}
	}
	int id3 = 0;
	if(id > id1) swap(id, id1);
	if(id == 1&& id1 == 2) id3 = 3;
	if(id == 2 &&id1 == 3) id3 = 1;
	if(id == 1 && id1 == 3) id3 = 2; 
	i++;
	for(;i<=n;i++){
		if(id3 == 1){
			ans += a[i].x;
		}
		if(id3 == 2){
			ans += a[i].y;
		}
		if(id3 == 3){
			ans += a[i].z;
		}
	}
	cout << ans << endl;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0) , cout.tie(0);
	int T;
	cin >> T;
	while(T--){
		solve();
	}
} 
