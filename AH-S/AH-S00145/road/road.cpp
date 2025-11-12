#include <bits/stdc++.h>
using namespace std;

struct node{
	int u,v,w;
}edge[1000005],jb[15005],ep[1000005],redge[1000005];
int f[15005];
int pcnt;
int siz[15005];
int to[15005],fa[15005];
int fp[15005],ft[15005];
int find(int x){
	if (x==f[x]) return x;
	return f[x]=find(f[x]);
}
void merge(int u,int v){
	int x=find(u),y=find(v);
	if (x!=y){
		if (siz[x]>siz[y]) f[y]=x,siz[x]+=siz[y];
		else f[x]=y,siz[y]+=siz[x];
	}
}
vector<int>a[15005];
int cnt;
vector<int>b[15005];
long long die[15005];
void dfs(int w,int ff){
	f[w]=ff;
	for(int i=0;i<a[w].size();i++){
		if (a[w][i]==ff) continue;
		to[a[w][i]]=b[w][i];
		dfs(a[w][i],w);
	}
}
bool vis[15005];
long long zt[15][15005];
bool cmp(node x,node y){
	return x.w<y.w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) f[i]=i,siz[i]=1;
	for(int i=1;i<=m;i++) cin>>edge[i].u>>edge[i].v>>edge[i].w;
	for(int i=1;i<=k;i++) for(int j=0;j<=n;j++) cin>>zt[i][j];
	long long ans=0,yt=0;
	if (n<=1000&&k<=5&&m<=100000){
		long long ans=1e18;
		for(int j=0;j<(1<<k);j++){
			pcnt=0;
			long long rsum=0;
			for(int i=1;i<=m;i++) redge[++pcnt]=edge[i];
			for(int i=0;i<k;i++){
				if (j&(1<<i)){
					rsum+=zt[i+1][0];
					for(int z=1;z<=n;z++){
						redge[++pcnt].u=i+n+1;
						redge[pcnt].v=z;
						redge[pcnt].w=zt[i+1][z];
					}
				}
			}	
			sort(redge+1,redge+1+pcnt,cmp);
			for(int i=1;i<=n+k+5;i++) f[i]=i,siz[i]=1;
			for(int i=1;i<=pcnt;i++){
				if (find(redge[i].u)!=find(redge[i].v)){
//					jb[++cnt]=edge[i];
					merge(redge[i].u,redge[i].v);
	//				a[edge[i].u].push_back(edge[i].v);
	//				a[edge[i].v].push_back(edge[i].u);
	//				b[edge[i].u].push_back(edge[i].w);
	//				b[edge[i].v].push_back(edge[i].w);
					rsum+=redge[i].w;
				}
			}
			ans=min(ans,rsum);
		}
		cout<<ans<<endl;
		return 0;
	}
	sort(edge+1,edge+1+m,cmp);
	for(int i=1;i<=m;i++){
		if (find(edge[i].u)!=find(edge[i].v)){
			jb[++cnt]=edge[i];
			merge(edge[i].u,edge[i].v);
			a[edge[i].u].push_back(edge[i].v);
			a[edge[i].v].push_back(edge[i].u);
			b[edge[i].u].push_back(edge[i].w);
			b[edge[i].v].push_back(edge[i].w);
			yt+=edge[i].w,ans+=edge[i].w;
		}
	}
	dfs(1,0);
	queue<int>q;
	for(int i=1;i<=n;i++) fp[i]=to[i],ft[i]=fa[i];
	for(int i=0;i<(1<<k);i++){
	//	cout<<i<<" ";
		for(int j=1;j<=n;j++) to[j]=fp[j],fa[j]=ft[j];
		long long sum=yt;
		for(int j=0;j<k;j++){
			while(!q.empty()) q.pop();
			if ((1<<j)&i){
				sum+=zt[j+1][0];
				long long sump=0,res1=1e18,res2=1e18,w=0,rp=1e18;
				for(int z=1;z<=n;z++){
					if (zt[j+1][z]<to[z]){
						if (res2>to[z]||(res2==to[z]&&rp<zt[j+1][z])) res2=to[z],w=z,rp=zt[j+1][z];
						sump+=(to[z]-zt[j+1][z]);
						q.push(z);
					}
					else res1=min(res1,zt[j+1][z]);
				}
				if (res1<res2){
					sum+=res1,sum-=sump;
					die[n+j+1]=res1;
					while(!q.empty()){
						int x=q.front();q.pop();
						if (fa[x]>n){
							if (die[fa[x]]>to[x]){
								sum-=(die[fa[x]]-to[x]);
								die[fa[x]]=to[x];
							}
						}
						to[x]=zt[j+1][x];
						fa[x]=n+j+1;
					}
				}
				else{
					die[n+j+1]=rp;
					sum+=res2,sum-=sump;
					while(!q.empty()){
						int x=q.front();q.pop();
						if (x==w) continue;
						if (fa[x]>n){
							if (die[fa[x]]>to[x]){
								sum-=(die[fa[x]]-to[x]);
								die[fa[x]]=to[x];
							}
						}
						to[x]=zt[j+1][x];
						fa[x]=n+j+1;
					}
				}
			}
		}
//		cout<<sum<<endl;
		ans=min(ans,sum);
	}	
	cout<<ans<<endl;
	return 0;
}
/*
 6 5 2
 1 2 7
 1 3 4
 2 4 1
 3 5 5
 3 6 4
 0 3 1000000 2 1000000 1000000 2
 0 1000000 1000000 1 0 1000000 1000000 
 */
