#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e4+20;
struct ed{
	int v,w; 
};
struct edg{
	int u,v,w;
	friend operator > (edg a,edg b){
		return a.w>b.w;
	}
};
int n,m,k;
int c[20],a[20][N],b[20];
int f[N];
int flag=0;
vector<ed>v[N];
ll cnt,ans,tsh=INT_MAX;
priority_queue<edg,vector<edg>,greater<edg> >q;
int find(int x){
	if(f[x]==x)return x;
	return f[x]=find(f[x]);
}
void solve(){
//	q.clear();
	while(q.size()>0)q.pop();
	for(int i=1;i<=n;i++){
		for(auto u:v[i]){
			q.push({i,u.v,u.w});
		}
		f[i]=i;
	}
	int cnt=n;
	for(int i=1;i<=k;i++){
		if(b[i]){
			++cnt;
			for(int j=1;j<=n;j++){
				q.push({n+i,j,a[i][j]});
			}
			f[n+i]=n+i;
		}
	}
	cnt--;
//	cout<<ans<<endl;
	while(cnt){
		edg fr=q.top();
		q.pop();
		int fa=find(fr.u),fb=find(fr.v);
		if(fa!=fb){
//			cout<<"connect "<<fa<<" and "<<fb<<" cost "<<fr.w<<endl;
			f[fa]=fb;
			cnt--;
			ans+=fr.w;
		}
	} 
	if(cnt==0)tsh=min(tsh,ans);
//	cout<<"------------------------------\n";
}
void dfs(int x){
	if(x>k){
		solve();
		return;
	}
	int t=ans;
	dfs(x+1);
	ans=t;
	ans+=c[x],b[x]=1;
	dfs(x+1);
	ans=t,b[x]=0;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		int u,vv,w;
		scanf("%d%d%d",&u,&vv,&w);
		v[u].push_back({vv,w});
	}
	for(int i=1;i<=k;i++){
		scanf("%d",&c[i]);
		if(c[i])flag=1;
		for(int j=1;j<=n;j++){
			scanf("%d",&a[i][j]);
		}
	}
	if(!flag){
		for(int i=1;i<=k;i++){
			b[i]=1;
		}
		solve();
	}
	else dfs(1);
	printf("%d",tsh);
	return 0;
}

