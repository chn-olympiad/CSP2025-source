#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n,m,k;
ll sum=0;
int f[20005];
bool vis[20005];
ll a[12][20005];
ll c[20005];
vector<pair<int,int>> v;

struct Node{
	int x,y,cost;
}edge[4000005];
int cnt=0;

bool cmp(Node x,Node y){
	return x.cost<y.cost;
}

int find(int x){
	if(f[x]==x)return x;
	return f[x]=find(f[x]);
}

void connect(int x,int y){
	f[find(x)]=find(y);
}

int main(){
	cin.tie(0),cout.tie(0);
	cin.sync_with_stdio(false);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for(int i=1;i<=n;i++)f[i]=i;
	for(int i=1;i<=m;i++){
		int x,y,z;
		cin >> x >> y >> z;
		edge[++cnt]={x,y,z};
	}
	for(int i=1;i<=k;i++){
		cin >> c[i];
		for(int j=1;j<=n;j++){
			cin >> a[i][j];
		}
	}
	ll sum=0;
	int p=0;
	sort(edge+1,edge+1+cnt,cmp);
	for(int i=1;i<=cnt;i++){
		if(find(edge[i].x)!=find(edge[i].y)){
			connect(edge[i].x,edge[i].y);
			sum+=edge[i].cost;
			p++;
			if(p==n-1)break;
		}
	}
	ll ans1=LLONG_MAX;
	for(int i=1;i<=k;i++){
		ans1=min(c[i],ans1);
	}
	cout<<min(ans1,sum);
	return 0;
} 
