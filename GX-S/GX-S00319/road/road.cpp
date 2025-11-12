#include<bits/stdc++.h>
using namespace std;
const int N=5e6+10;
typedef pair<long long,long long> pii;
int n,m,k,vis[N],cnt=1,f[N];
int q[N][2],r[11][N];
long long ans=0;
priority_queue<pii,vector<pii>,greater<pii>>pq;
int find(int x){
	while(f[x]!=x){x=f[x];}
	return x;
}
void merge(int x,int y){
	f[find(x)]=find(y);
	return ;
}
void woyingl(){
	while(cnt!=n&&!pq.empty()){
		int x=pq.top().second,y=pq.top().first;
		pq.pop();
		if(find(q[x][0])==find(q[x][1]))continue;
		merge(q[x][0],q[x][1]);
		ans+=y;
		cnt++;
	}
    return ;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)f[i]=i;
	for(int i=1;i<=m;i++){
		int x,y,z;
		cin>>x>>y>>z;
		pq.push({z,i});
		q[i][0]=x;
		q[i][1]=y;
	}
	for(int i=1;i<=k;i++){
		for(int j=0;j<=n;j++){
			cin>>r[i][j];
		}
	}
	int u=1;
	for(int v=1;v<=k;v++){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				pq.push({r[v][0]+r[v][i]+r[v][j],m+u});
				q[m+u][0]=i;
				q[m+u][1]=j;
				u++;
			}
		}
	}
	woyingl();
	cout<<ans;
	return 0;
}
