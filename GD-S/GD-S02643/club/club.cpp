#include<bits/stdc++.h>
#define rep(i,a,b,c) for(int i = (a); i <= (b); i+=(c))
#define per(i,a,b,c) for(int i = (a); i >= (b); i-=(c))
#define ALL(a) (a).begin(), (a).end()
using namespace std;

const int INF = INT_MAX / 2;
const int N = 1e5 + 5;

struct Club{
	int id;
	int club;
	int score;
	friend bool operator < (Club x, Club y){
		return x.score > y.score;
	}
}a[3 * N];
int vis[N];
void solve(){

	memset(vis,false,sizeof(vis));
//	vector<int> c1,c2,c3;
    int ans = 0;

	int n;
	cin >> n;
	rep(i,1,n,1) {
		cin >> a[i].score >> a[i + n].score >> a[i + n + n].score ;
		a[i].id = a[i + n].id = a[i + n + n].id = i;
		a[i].club = 1, a[i + n].club = 2, a[i + n + n].club = 3;
	}
	sort(a + 1, a + n + n + n + 1);

	int c1=0,c2=0,c3=0;

	rep(i,1,3 * n,1){
		int s = a[i].score , id = a[i].id, c = a[i].club ;
		if(c == 1){
			if(c1 * 2 >= n) continue;
			if(vis[id]) continue;
			ans += s;
			vis[id] = true;
			c1++;
		}
		if(c == 2){
			if(c2 * 2 >= n) continue;
			if(vis[id]) continue;
			ans += s;
			vis[id] = true;
			c2++;
		}
		if(c == 3){
			if(c3 * 2 >= n) continue;
			if(vis[id]) continue;
			ans += s;
			vis[id] = true;
			c3++;
		}

	}
	cout << ans << endl;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);

	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	while(T--) solve();

	return 0;
} //it took me 1h30min to work out, too annoying . I'm stupid!!!
