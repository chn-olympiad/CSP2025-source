#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF 0x3f3f3f3f
#define mod 1000000007
#define ari(x) array<int,(x)>
#define lowbit(x) ((x) -(x))

const int N = 1e5+5;
ari(4) a[N];
int p[N],c[5],n;
void solve(){
	cin>>n;
	ll ans = 0;
	c[1] = c[2] = c[3] = 0;
	for(int i = 1;i <= n;i++){
		cin>>a[i][1]>>a[i][2]>>a[i][3];
		int ma = max({a[i][1],a[i][2],a[i][3]});
		if(ma == a[i][1]){
			c[1]++;
			p[i] = 1;
			a[i][0] = max(a[i][2],a[i][3]);
		}else if(ma == a[i][2]){
			c[2]++;
			p[i] = 2;
			a[i][0] = max(a[i][1],a[i][3]);
		}else{
			c[3]++;
			p[i] = 3;
			a[i][0] = max(a[i][1],a[i][2]);
		}
		ans+=ma;
	}
	int mp = 0;
	if(c[1] > n/2) mp = 1;
	if(c[2] > n/2) mp = 2;
	if(c[3] > n/2) mp = 3;
	if(mp == 0){
		cout<<ans<<"\n";
		return;
	}
	for(int i = 1;i <= n;i++){
		if(p[i] == mp) a[i][0]-=a[i][p[i]];
		else a[i][0] = INF;
	}
	sort(a+1,a+n+1);
	for(int i = n/2+1,j = 1;i <= max({c[1],c[2],c[3]});i++,j++)
		ans+=a[i][0];
	cout<<ans<<"\n";
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--) solve();
	return 0;
}
