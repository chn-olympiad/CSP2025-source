#include<iostream>
#include<algorithm>
using namespace std;
const int N = 100001;

int T,n,ans,dis[N],a[N][4];

bool specialA(){
	for(int i = 1;i <= n;++i)
		if(a[i][2] || a[i][3]) return false;
	return true;
}
bool cmpA(int a,int b){return a > b;}

void dfs(int x,int at,int b,int c){
	if(x == n+1){
		int sum = 0;
		for(int i = 1;i <= n;++i)
			sum += a[i][dis[i]];
		ans = max(ans,sum);
		return;
	}
	int vis[4] = {0,at,b,c};
	for(int i = 1;i <= 3;++i){
		if(vis[i]+1 > n/2) continue;
		++vis[i];
		dis[x] = i;
		dfs(x+1,vis[1],vis[2],vis[3]);
		--vis[i];
	}
	return;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin >> T;
	while(T-- && cin >> n){
		for(int i = 1;i <= n;++i)
			cin >> a[i][1] >> a[i][2] >> a[i][3];
		if(specialA()){
			int f[n+2];
			for(int i = 1;i <= n;++i) f[i] = a[i][1];
			sort(f+1,f+n+1,cmpA);
			for(int i = 1;i <= n/2;++i) ans += f[i];
		}else dfs(1,0,0,0);
		cout << ans << '\n';ans = 0;
	}
	return 0;
}
