#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
const int M = 1e4+10;
int pre[N],cnt;
int n,m,k;
int c[20],a[20][M];
long long ans = 0;
struct Edge{
	int from,to,next,val;
}edge[2*N];
void addedge(int u,int v,int val){
	cnt++;
	edge[cnt].from = u;
	edge[cnt].to = v;
	edge[cnt].next = pre[u];
	edge[cnt].val = val;
	cnt = pre[u];
}
void find(){
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for(int i,x,y,z;i<=m;i++){
		cin >> x >> y >> z;
		ans += z;
		addedge(x,y,z);
		addedge(y,x,z);
	}
	for(int i = 1;i<=k;i++){
		cin >> c[i];
		for(int j = 1;j<=n;j++){
			cin >> a[i][j];
		}
	}
	cout << ans;
	return 0;
}

