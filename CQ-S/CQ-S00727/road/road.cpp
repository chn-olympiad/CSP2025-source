#include<bits/stdc++.h>
using namespace std;
#define MAXN 1000000
#define MAXM 11000
struct node{
	int x,y,val;
}edge[MAXN+5];
struct skk{
	int val,id;
}a[15][MAXM+5];
int cost[15];
bool cmp(node u,node v){
	return u.val<v.val;
}
bool cmp1(skk u,skk v){
	return u.val<v.val; 
}
int n,m,k,fa[MAXN+5];
int find(int x){
	if(fa[x]==x) return x;
	fa[x]=find(fa[x]);
	return fa[x];
}
bool merge(int x,int y){
	x=find(x),y=find(y);
	if(x==y) return 0;
	fa[x]=y;
	return 1;
}
vector<node> G[2005];
long long ans[2005],sum[2005],cnt1[2005],INF=1e18;
void solve(int now,int pre,int x){
	//cout<<now<<' '<<pre<<' '<<G[now].size()<<' '<<G[pre].size()<<' '<<x<<endl;
	for(int i=1;i<=n+k;i++) fa[i]=i;
	vector<node> vec;
	int cnt=0,tot1=1,tot2=0;
	while(cnt<n-1+cnt1[now]&&(tot1<=n||tot2<G[pre].size())){
		if(x!=0&&tot1<=n&&(a[x][tot1].val<=G[pre][tot2].val||tot2==G[pre].size())){
			int ret=merge(x+n,a[x][tot1].id);
			ans[now]+=a[x][tot1].val*ret;
			cnt+=ret;
			if(ret==1) vec.push_back({x+n,a[x][tot1].id,a[x][tot1].val});
			tot1++;
		}
		else{
			int ret=merge(G[pre][tot2].x,G[pre][tot2].y);
			ans[now]+=G[pre][tot2].val*ret;
			cnt+=ret;
			if(ret==1) vec.push_back({G[pre][tot2].x,G[pre][tot2].y,G[pre][tot2].val});
			tot2++;
		}
	}
	if(cnt<n-1+cnt1[now]) ans[now]=INF;
	if(pre==0&&now==0) G[0].clear();
	for(auto v:vec) G[now].push_back(v);
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
		cin>>edge[i].x>>edge[i].y>>edge[i].val;
	sort(edge+1,edge+m+1,cmp);
	for(int i=1;i<=k;i++){
		cin>>cost[i];
		for(int j=1;j<=n;j++) cin>>a[i][j].val,a[i][j].id=j;
	}
	for(int i=1;i<=k;i++) sort(a[i]+1,a[i]+n+1,cmp1);
	//cout<<"Doeff "<<n<<' '<<m<<' '<<k<<endl;
	for(int i=1;i<=m;i++) G[0].push_back(edge[i]);
	solve(0,0,0);
	for(int i=1;i<(1<<k);i++){
		//cout<<i<<endl;
		for(int j=1;j<=k;j++){
			if((1<<(j-1))&i){
				int k=i^(1<<(j-1));
				cnt1[i]=cnt1[k]+1;
				solve(i,k,j);
				sum[i]=sum[k]+cost[j];
				break;
			}
		}
		//cout<<G[i].size()<<endl;
	}
	long long mn=LONG_LONG_MAX;
	for(int i=0;i<(1<<k);i++) mn=min(mn,ans[i]+sum[i]);
	//cout<<ans[1]<<' '<<sum[1]<<endl;
	printf("%lld\n",mn);
} 
