#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;

const int N=1e4+25,M=15; 

int T,n,m,k;
long long a[N][N],ans=1e18;
long long c[M],p[M][N],d[N]; 
bool v[M],v2[N];

long long prim(int S){
	long long res=0;
	memset(d,0x3f,sizeof(d));
	memset(v2,0,sizeof(v2));
	priority_queue<pair<long long,int>> q;
	q.push(make_pair(0,S));d[S]=0;
	while(!q.empty()){
		int f=q.top().second;q.pop();
		v2[f]=1;
		for(int i=1;i<=S;i++){
			if(i==f) continue;
			int y=i;long long w=a[f][i];
			//if(v2[y]) continue;
			if(d[y]>w){
				d[y]=w;
				if(!v2[y]) q.push(make_pair(-d[y],y));
			}
		}
	}
	for(int i=1;i<=n;i++) res+=d[i];
	return res;
}

void dfs(int h){
	if(h>k){
		long long ret=0;int cnt=0;
		for(int i=1;i<=k;i++){
			if(v[i]){
				//cout<<i<<" "; 
				cnt++;ret+=c[i];
				for(int j=1;j<=n;j++) a[n+cnt][j]=a[j][n+cnt]=p[i][j];
			}
		}
		long long res=prim(n+cnt);
		ans=min(ans,prim(n+cnt)+ret);
		return;
	}
	v[h]=0;dfs(h+1);
	v[h]=1;dfs(h+1);
	return;
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie();cout.tie();
	cin>>n>>m>>k;
	memset(a,0x3f,sizeof(a));
	for(int i=1;i<=m;i++){
		int x,y,t;
		cin>>x>>y>>t;
		a[x][y]=a[y][x]=t;
	} 
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++) cin>>p[i][j];
	}
	if(k==0){
		cout<<prim(n);return 0;
	}
	dfs(1);
	cout<<ans;
	return 0;
}
 
