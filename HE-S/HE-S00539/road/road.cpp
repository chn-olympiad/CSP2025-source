#include <bits/stdc++.h>
#define PII pair<int,int>
#define ll long long
using namespace std;
const int N=10510,M=1000501;
struct Edge{int u,v,w;};
vector<Edge>a,a1;
int cmp(Edge x,Edge y){
	return x.w<y.w;
}int n,m,k,c[20],cnta,p[20][N];
int fa[N],cntf;
int fnd(int x){
	if(fa[x]==x)return x;
	return fa[x]=fnd(fa[x]);
}bool b[20];
ll ans,ttt=clock();
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1,u,v,w;i<=m;i++){
		scanf("%d%d%d",&u,&v,&w);
		a.push_back((Edge){u,v,w});
		a.push_back((Edge){v,u,w});
	}cnta+=m;for(int i=1;i<=k;i++){
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++){
			scanf("%d",&p[i][j]);
		}
	}sort(a.begin(),a.end(),cmp);
	for(int i=1;i<=n;i++)fa[i]=i;
	for(auto i:a){
		if(fnd(i.u)==fnd(i.v)){
			continue;
		}fa[fnd(i.u)]=fnd(i.v);
		ans+=i.w;
	}ll res=0;
	for(int z=1;z<=k;z++){a1=a;
		if(clock()-ttt>900)break;
		res+=c[z];ll ans1=res;
		int cntf=n+z-1;
		for(int i=1;i<=n;i++){
			a1.push_back((Edge){i,n+z,p[z][i]});
			a1.push_back((Edge){n+z,i,p[z][i]});
		}sort(a1.begin(),a1.end(),cmp);
		if(clock()-ttt>900)break;
		for(int i=1;i<=n+z;i++)fa[i]=i;
		for(auto i:a1){
			//cout<<i.w<<' ';
			if(clock()-ttt>900)break;
			if(fnd(i.u)==fnd(i.v)){
				continue;
			}fa[fnd(i.u)]=fnd(i.v);
			ans1+=i.w;
		}if(ans1<ans){
			ans=ans1;
			a=a1;
		}else{res-=c[z];
			a.push_back({1,n+z,0});
		}//cout<<ans1<<' ';
	}printf("%lld",ans);
	return 0;
}

