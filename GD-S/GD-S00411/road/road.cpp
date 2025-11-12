#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+13;
const int N = 2401;

struct r{
	int u,v,w;
}r[maxn];

int n,m,k;
int d[maxn];
int c[maxn];
int a[N][N];
int cnt[maxn];
bool re[maxn];

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> m >> k;
	for(int i=1;i<=m;i++){
		cin >> r[i].u >> r[i].v >> r[i].w;
		d[i] = r[i].w;
		
		cnt[r[i].u]++;
		cnt[r[i].v]++;
		
	}
	for(int i=1;i<=k;i++){
		cin >> c[maxn];
		for(int j=1;j<=n;j++){
			cin >> a[i][j];
		}
	}
	
	int ans=0,cntn=0;
	for(int i=1;i<=m;i++){
		if(!re[i]){
			if(cnt[r[i].u]==1 || cnt[r[i].v]==1){
				cntn++;
				re[i] = 1;
				ans += r[i].w;
				cnt[r[i].u]--;
				cnt[r[i].v]--;
			}
		}
	}
	
	sort(d+1, d+1+n);
	for(int i=1;i<=n-cntn;i++){
		ans += d[i];
	}
	
	cout << ans << endl;
	
	
	
	return 0;
	
} 
