#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,k,u,v,w,b[12][10010],c[12],cnt,fa[10010],cnt2,ans;
struct p{
	ll u,v,w;
}e[1000010],x;
vector<p>a[10010];
bool cmp(p x,p y){
	return x.w<y.w;
}
ll kru(){
	sort(e+1,e+cnt+1,cmp);
	for(int i=1;i<=n;i++)fa[i]=i;
	int r=0;
	for(cnt2=0;cnt2<n-1;){
		r++;
		if(fa[e[r].u]!=fa[e[r].v]){
			cnt2++;
			fa[e[r].v]=e[r].u;
			ans+=e[r].w;
			//cout<<e[r].u<<" "<<e[r].v<<" "<<e[r].w<<endl; 
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		x.u=u,x.v=v,x.w=w;
		a[u].push_back(x),e[++cnt]=x;
		swap(x.u,x.v);
		a[v].push_back(x),e[++cnt]=x;
	}
	for(int i=1;i<=k;i++){
		//cout<<114514<<endl;
		cin>>c[i];
		for(int j=1;j<=n;j++)cin>>b[i][j];
		for(int j=1;j<=n;j++){
			for(int l=j+1;l<=n;l++){
				x.u=i,x.v=j,x.w=b[i][j]+b[i][l];
				a[j].push_back(x),e[++cnt]=x;
			}
		}
	}
	kru();
	cout<<ans;
	return 0;
}
