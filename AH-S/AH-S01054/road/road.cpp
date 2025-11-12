#include<bits/stdc++.h>
using namespace std;
vector<int> v[1000015];
int n,m,k,w[1015][1015],jg[1000015],cnt[100015];
long long mi=1000000000000000000,ans=0;
bool used[1000005];
bool check(){
	for(int i=1;i<=n;i++){
		if(used[i]==0) return 0;
	}
	return 1;	
}
void bfs(int x){
	if(check()){
		if(mi>ans)mi=ans;
		return;
	}
	queue<int> q;
	q.push(x);
	while(!q.empty()){
		int nx=q.front();
		q.pop();
		for(int i=0;i<cnt[nx];i++){
			int to=v[nx][i];
			if(used[to]==0){
				ans+=jg[to];
				ans+=w[nx][to];
				used[to]=1;
				bfs(to);
				used[to]=0;
				ans-=jg[to];
				ans-=w[nx][to];
			}
		}
	}
	return;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		v[x].push_back(y);
		v[y].push_back(x);
		w[x][y]=w[y][x]=z;
		cnt[x]++,cnt[y]++;
	}
	for(int i=1;i<=k;i++){
		int x;
		scanf("%d",&x);
		jg[n+i]=x;
		for(int j=1;j<=n;j++){
			int y;
			scanf("%d",&y);
			v[n+i].push_back(j);
			v[j].push_back(n+i);
			cnt[j]++,cnt[n+i]++;
			w[n+i][j]=w[j][n+i]=y;
			}
		}
	used[1]=1;
	bfs(1);
	cout<<mi;
	return 0;
}
