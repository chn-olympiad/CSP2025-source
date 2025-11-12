#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define lowbit(x) (x&-x)
#define pii pair<int,int>
#define N 100010
#define M 200010
int T,a[N][4],n,ans,maxn,haf,b[N];
int cnt[4],cost[N],lc;
bool vis[N];
int main(){
	freopen("club.in","r",stdin),freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> T;
	while(T--){cin >> n;cnt[1] = cnt[2] = cnt[3] = ans = 0;lc = 0;
		haf = (n>>1);
		for(int i = 1;i <= n;++i){
			cin >> a[i][1] >> a[i][2] >> a[i][3];
			maxn = max(max(a[i][1],a[i][2]),a[i][3]);
			if(maxn == a[i][1]){++cnt[1];b[i] = 1;}
			else if(maxn == a[i][2]){++cnt[2];b[i] = 2;}
			else{++cnt[3];b[i] = 3;}
			ans += maxn;
		}
		if(cnt[1] <= haf && cnt[2] <= haf && cnt[3] <= haf){cout << ans << '\n';continue;}
		int now;
		if(cnt[1] > haf)now = 1;if(cnt[2] > haf)now = 2;if(cnt[3] > haf)now = 3;
		for(int i = 1;i <= n;++i){if(b[i] != now)continue;
			if(now == 1)cost[++lc] = a[i][1] - max(a[i][2],a[i][3]);
			if(now == 2)cost[++lc] = a[i][2] - max(a[i][1],a[i][3]);
			if(now == 3)cost[++lc] = a[i][3] - max(a[i][2],a[i][1]);
		}
		sort(cost+1,cost+lc+1);
		for(int i = 1;i <= lc && cnt[now] > haf;++i)ans -= cost[i],--cnt[now];
		cout << ans << '\n';
	} 
	
	return 0;
} 
