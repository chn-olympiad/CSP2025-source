#include<bits/stdc++.h>
using namespace std;
const int N=1e6+25;
#define int long long
struct stu{
	int u,v,w;
}k[N];
int n,m,o,c[20],a[20][N],fa[N],ans=0,v[20],s[N],d[20];
bool cmp(stu a,stu b){
	return a.w<b.w;
}
int getfa(int x){
	if(x==fa[x]) return x;
	return fa[x]=getfa(fa[x]);
}
vector<pair<int,int> >g[N]; 
signed main(){
	freopen("road.in ","r",stdin);freopen("road.out","w",stdout);
	cin>>n>>m>>o;
	for(int i=1;i<=m;i++){
		cin>>k[i].u>>k[i].v>>k[i].w;
		g[k[i].u].push_back({k[i].v,k[i].w});
		g[k[i].v].push_back({k[i].u,k[i].w});
	}
	for(int i=1;i<=o;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	if(o==0){
		for(int i=1;i<=n;i++) fa[i]=i;
		sort(k+1,k+1+m,cmp);
		for(int i=1;i<=m;i++){
			int p=k[i].u,q=k[i].v;
			cout<<p<<" "<<q<<endl;
			if(getfa(p)==getfa(q)) continue;
			else{
				fa[getfa(p)]=getfa(q);
				ans+=k[i].w;
			}
		}
		cout<<ans;
		return 0;
	}
	else{
		for(int i=1;i<=o;i++){
			for(int j=1;j<=n-1;j++){
				for(int l=j+1;l<=n;l++){
					m++;
					k[m].u=j,k[m].v=l,k[m].w=a[i][j]+a[i][l];
				}
			}
		}
		sort(k+1,k+1+m,cmp);
		for(int i=1;i<=n;i++) fa[i]=i;
		for(int i=1;i<=m;i++){
			int p=k[i].u,q=k[i].v;
			if(getfa(p)==getfa(q)) continue;
			else{
				fa[getfa(p)]=getfa(q);
				ans+=k[i].w;
			}
		}
		cout<<ans;
	}
	return 0;
}
