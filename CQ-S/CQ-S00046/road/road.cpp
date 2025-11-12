#include <bits/stdc++.h>
using namespace std;
int n,m,k,uu,vv,cnt,head[10015],to[2020005],next1[2020005],S,poyupo;
long long ww,qw,dist[2020005],zhi[2020005],c[15],d[12][10015],ans = 1e18,now,qwqwq,wqwqw;
bool fdppp;
#define add(aa,bb,cc) (++cnt,to[cnt] = bb,zhi[cnt] = cc,next1[cnt] = head[aa],head[aa] = cnt)
priority_queue<pair<long long,int> >q;
bool vis[10015];
long long prim(){
	for(int i = 1;i <= n+k+1;++i) vis[i] = 0,dist[i] = 1e18;
	while(!q.empty()) q.pop();
	dist[1] = 0,wqwqw = 0;
	q.push({0,1});
	while(!q.empty()){
		int x = q.top().second;
		q.pop();
		if(vis[x] == 1) continue;
		vis[x] = 1,++wqwqw;
		if(wqwqw == poyupo + n) break;
		for(int i = head[x];i;i = next1[i]){
			int y = to[i];
			if(y > n && (!(S & (1<<(y-n-1))))) continue;
			if(vis[y]) continue;
			//cout << x << " " << y << " " << zhi[i] << endl;
			if(dist[y] > zhi[i]){
				dist[y] = zhi[i];
				q.push({-dist[y],y});
			}
		}
		//for(int i = 1;i <= n+k;++i) cout << dist[i] << " ";
		//cout << endl;
	}
	long long qqqqq = 0;
	for(int i = 1;i <= n;++i) qqqqq += dist[i];
	//for(int i = 1;i <= n+k;++i) cout << dist[i] << " ";
	//cout << endl;
	for(int i = n+1;i <= n+k;++i) if(S & (1<<(i-n-1))) qqqqq += dist[i];//cout << i << " ";}
	//cout << endl;
	return qqqqq;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> n >> m >> k;
	for(int i = 1;i <= m;++i){
		cin >> uu >> vv >> ww;
		add(uu,vv,ww),add(vv,uu,ww);
	}
	if(k == 0){
		cout << prim();
		return 0;
	}
	for(int i = 1;i <= k;++i){
		cin >> c[i];
		if(c[i] != 0) fdppp = 1;
		for(int j = 1;j <= n;++j){
			cin >> d[i][j];
			add(n+i,j,d[i][j]),add(j,n+i,d[i][j]);
		}
	}
	if(fdppp == 0){
		S = (1<<k)-1;
		cout << prim();
		return 0;
	}
	while(S < (1<<k)){
		now = 0,poyupo = 0;
		for(int i = 1;i <= k;++i) if(S & (1<<(i-1))) now += c[i],++poyupo;
		long long qfr = prim();
		if(qfr+now < ans) ans = qfr+now;
			//cout << S << " " << now + qfr << " " << qfr << endl << endl;
		++S;
	}
	cout << ans;
	return 0;
}
