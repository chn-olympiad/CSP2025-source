#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5+1;
ll n,T;
ll a[N][4],ans;
ll t[4][N+1];
struct node{
	ll h;
	ll w;
}d[N+2];
ll vis[N];
ll init;
bool cmp(node x,node y){
	return x.w < y.w;
}
int nuo(int hao,int x,int y,int top){
	for(int i=1;i <= top;i++){
		d[i].w = -(a[t[hao][i]][x]-a[t[hao][i]][hao]);
		d[i].h = t[hao][i];
	}
	for(int i=top+1;i <= 2*top;i++){
		d[i].w = -(a[t[hao][i-top]][y]-a[t[hao][i-top]][hao]);
		d[i].h = t[hao][i-top];
	}
	sort(d+1,d+top+top+1,cmp);
	ll h = 0,i = 1;
	for(;i <= top-(n/2)+h;i++){
		if(vis[d[i].h]){
			h++;
			continue;
		}
		vis[d[i].h] = 1;
		ans -= d[i].w;
	}
	return i;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> T;
	while(T--){
		cin >> n;
		for(int i=1;i <= n;i++){
			cin >> a[i][1] >> a[i][2] >> a[i][3];
			if(a[i][1] >= a[i][2] && a[i][1] >= a[i][3]){
				t[1][++t[1][0]] = i;
				ans += a[i][1];
			}else if(a[i][2] >= a[i][1] && a[i][2] >= a[i][3]){
				t[2][++t[2][0]] = i;
				ans += a[i][2];
			}else if(a[i][3] >= a[i][1] && a[i][3] >= a[i][2]){
				t[3][++t[3][0]] = i;
				ans += a[i][3];
			}
		}
		if(t[1][0] > n/2){
			init = nuo(1,2,3,t[1][0]);
			cout << ans << "\n";
		}else if(t[2][0] > n/2){
			init = nuo(2,1,3,t[2][0]);
			cout << ans << "\n";
		}else if(t[3][0] > n/2){
			init = nuo(3,1,2,t[3][0]);
			cout << ans << "\n";
		}else{
			cout << ans << "\n";
		}
		ans = 0;
		t[1][0] = t[2][0] = t[3][0] = 0;
		memset(vis,0,sizeof(vis));
	}
	return 0;
}
