#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct road{
	int from,to,val;
};

//vector<road> g[10009];
road q[2][1000009];
int xb[2];
int n,m,k;
int city[19],rd[19][10009];
int hd[10009],size[10009],fa[10009];
bool bj[10009],cnt;
ll ans[3];
int now;

int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}

void merge(int a,int b){
	int x=find(a);
	int y=find(b);
	if(x==y) return;
	if(size[x]>size[y]) swap(x,y);
	fa[x]=y;
	size[y]+=size[x];
}

bool cmp(road i,road j){
	return i.val<j.val;
}

void kruskul(int u,int mq){
	for(int i=1;i<=xb[mq%2];i++){
		if(find(q[mq%2][i].from)==find(q[mq%2][i].to)) continue;
		if(!bj[q[mq%2][i].from]){
			bj[q[mq%2][i].from]=1;
			cnt++;
		}
		if(!bj[q[mq%2][i].to]){
			bj[q[mq%2][i].to]=1;
			cnt++;
		}
		ans[u]+=q[mq%2][i].val;
		q[(mq+1)%2][++xb[(mq+1)%2]]=q[mq%2][i];
		merge(q[mq%2][i].from,q[mq%2][i].to);
		if(cnt==n+now) break;
	}
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
//		g[x].push_back({x,y,z});
//		g[y].push_back({y,x,z});
		q[0][i]={x,y,z};
	}
	xb[0]=m;
	for(int ij=1;ij<=n;ij++) size[ij]=1,fa[ij]=ij;
	sort(q[0]+1,q[0]+m+1,cmp);
	kruskul(1,0);
//	cout<<ans[1]<<endl;
//	cout<<q[1][1].from<<" "<<q[1][1].to<<endl;
//	cout<<xb[1]<<endl;
	for(int i=1;i<=k;i++){
		ans[2]=0;
		scanf("%d",&city[i]);
		for(int j=1;j<=n;j++){
			scanf("%d",&rd[i][j]);
		}
//		xb[i%2]=xb[(i-1)%2];
		for(int j=1;j<=n;j++){
			q[i%2][++xb[i%2]]={j,n+now+1,rd[i][j]};
		}
		for(int ij=1;ij<=n+now+1;ij++) size[ij]=1,fa[ij]=ij;
		sort(q[i%2]+1,q[i%2]+xb[i%2]+1,cmp);
//		for(int ij=1;ij<=xb[i%2];ij++) printf("%d %d %d\n",q[i%2][ij].from,q[i%2][ij].to,q[i%2][ij].val);
//		cout<<endl;
		kruskul(2,i);
		if(ans[1]>ans[2]+city[i]){
			now++;
			ans[1]=ans[2]+city[i];
		}
		else{
			swap(q[0],q[1]);
			xb[(i+1)%2]=xb[i%2];
		}
	}
	printf("%lld",ans[1]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
