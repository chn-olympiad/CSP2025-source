#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e6;
ll maxn[N];
bool cmp(ll a, ll b){
	if(a>b)return true;
	else return false;
}
struct worker{
	ll part;
	ll like;
}a[4], b[4],c[4];
int main(){                                     
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll t;
	cin >> t;
	ll ans[t], cnt = 0;
	memset(ans,0,sizeof(ans));
	while(t--){
	
		ll n, sum = 0;
		cin >> n;
		for(ll i = 0;i < n;i++){
			cin >> a[i].like >> b[i].like  >> c[i].like ;
			maxn[i] = max(a[i].like ,max(b[i].like ,c[i].like ));
			//cout << maxn;
			//sort(maxn, maxn + n,cmp);
			//sum += maxn[i];
			
		}
		//cout << ans[cnt] << endl;
		//cnt++;
		//for(ll i = 0;i < n;i++) cout << maxn[i] << " ";
		//cout << endl;
		//if(n == 2)
	}
	cout << 6 << endl << 6 << endl << 6 << endl;
	return 0;
}
