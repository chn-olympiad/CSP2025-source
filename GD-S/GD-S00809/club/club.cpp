#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pdd;
const int N = 1e5 + 31;

int n,a[N][4],d[N][4],c[4],f[4];
priority_queue<pdd> q,v[4];

bool cmp(int x,int y){
	return f[x] > f[y];
}

void solve(){
	scanf("%d",&n);
	for(int i = 1;i <= 3;i++){
		c[i] = 0;
		while(!v[i].empty())
			v[i].pop();
	}
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= 3;j++){
			scanf("%d",&a[i][j]);
			d[i][j] = j; f[j] = a[i][j];
		}
		sort(d[i] + 1,d[i] + 4,cmp);
		q.push(make_pair(a[i][d[i][1]],i));
	}
	int ans = 0;
	while(!q.empty()){
		pdd x = q.top(); q.pop();
		int val = x.first,uid = x.second;
		if(c[d[uid][1]] < n / 2){
			ans += val; c[d[uid][1]]++;
			v[d[uid][1]].push(pdd(a[uid][d[uid][2]] - a[uid][d[uid][1]],uid));
		}else{
			int lid = v[d[uid][1]].top().second;
			if(a[lid][d[uid][1]] + a[uid][d[uid][2]] < a[lid][d[lid][2]] + a[uid][d[uid][1]]){
				v[d[uid][1]].pop();
				v[d[uid][1]].push(pdd(a[uid][d[uid][2]] - a[uid][d[uid][1]],uid));
				ans += (a[lid][d[lid][2]] + a[uid][d[uid][1]]) - a[lid][d[uid][1]];
				c[d[lid][2]]++;
			}else{
				v[d[uid][2]].push(pdd(a[uid][d[uid][2]] - a[uid][d[uid][1]],uid));
				ans += a[uid][d[uid][2]];
				c[d[uid][2]]++;
			}
		}
	}
	printf("%d\n",ans);
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t; scanf("%d",&t);
	while(t--) solve();
	return 0;
}
