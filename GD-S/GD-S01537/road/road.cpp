#include <bits/stdc++.h>
#define P pair<long long,long long>
#define mp makepair
using namespace std;
const int N=12e3;
struct ed { long long to,w;} ;
vector<ed> e[N];
long long n,m,k,u,v,w,ans,cnt,ff,oo[N],f[N];
priority_queue<P,vector<P>,greater<P> >q;
int main() {
	freopen ("road.in","r",stdin);
	freopen ("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >>n >>m >>k;
	for (int i=1;i<=n+k+1;i++) {
		f[i]=i;
	}
	for (int i=1;i<=m;i++) {
		cin >>u >>v >>w;
		e[u].push_back({v,w});
		e[v].push_back({u,w});
	}
	for (int i=1;i<=k;i++) {
		cin >>ff;
		for (int j=1;j<=n;j++) {
			cin >>oo[j];
			for (int jj=1;jj<j;jj++) {
				e[jj].push_back({j,oo[j]+oo[jj]});
				e[j].push_back({jj,oo[j]+oo[jj]});
			}
		}
	}
	q.push({0,1});
	while (!q.empty()) {
		int ww=q.top().first,vv=q.top().second;
		q.pop();
		if (f[vv]==1 && vv!=1) continue;
		cnt++;
		ans+=ww;
		f[vv]=1;
		if (cnt==n) break;
		for (int i=0,len=e[vv].size();i<len;i++) {
			if (f[e[vv][i].to]!=1) q.push({e[vv][i].w,e[vv][i].to});
		}
	}
	cout <<ans;
	return 0;
}

