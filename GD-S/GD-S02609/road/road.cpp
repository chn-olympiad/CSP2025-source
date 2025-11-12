#include <bits/stdc++.h>
#define ll long long
using namespace std;
bool Mbe;
const int N = 1e6+34; 
ll n,m,k;

struct rd{
	ll x, y,w;
	friend bool operator <(rd a, rd b){
		return a.w < b.w;
	}
};

vector<rd> v;
ll c[N],a[11][N],fa[N];

ll fd(ll x){
	if (fa[x] == x) return x;
	return fa[x] = fd(fa[x]);
}


bool Med;
int main(){
	freopen("road.in","r",stdin); 
	freopen("road.out","w",stdout); 
//	freopen("C:\\Users\\Administrator\\Desktop\\题目\\road\\road3.in","r",stdin); 
//	freopen("out.txt","w",stdout); 
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
//	cerr << "Mem: " << double(&Mbe-&Med) / 1048576.0 << "MB\n";
	cin >> n >> m >> k;
	for (int i = 1; i <= n;i++) fa[i] = i;
	for (int i =1 ; i <= m;i++){
		ll x,y,w;
		cin >> x >> y>>w;
		v.push_back({x,y,w});
	}
	for (ll j = 1; j<=k;j++){
		cin >> c[j];
		for (ll i = 1; i <= n;i++) cin >> a[j][i];
	}
	
	// 暴力建边，然后跑Krucal
	for (int j = 1; j <= k;j++){
		ll pc = c[j];
		for (int i = 1; i < n;i++){
			ll pfrom = a[j][i];
			for (int o = i+1; o <= n;o++){
				ll pto = a[j][o];
				ll w = pfrom + pc + pto;
				v.push_back({i,o,w});
			}
		} 
	}
//	cout << v.size() << '\n';
	sort(v.begin(),v.end());
	ll new_m = v.size();
	ll cnt=0,ans=0;
	for (int i = 0; i < new_m;i++){
		ll x =v[i].x, y=v[i].y, w=v[i].w;
		ll xx = fd(x),yy=fd(y);
		
		if (xx != yy){
			fa[xx]=yy;
			ans += w;
			++cnt;	
			if (cnt == n-1) break;	
		}
		
	}
	
	cout << ans << '\n';
	
//	cerr << "Time: " << double(clock()*1.0 / CLOCKS_PER_SEC)<<'\n';
	
		
	return 0;
}

