#include<bits/stdc++.h>
using namespace std;
const int M=1e6+1e5+1e4;
const int N=1e4+5;
int n,m,k,id[N],cnt;
struct edge{
	int u,v,c;
}e[M];
int ask(int x){
	if(id[x]==x){
		return x;
	}
	int y=ask(id[x]);
	id[x]=y;
	return id[x];
}
void merge(int x,int y){
	int idx=ask(x),idy=ask(y);
	id[idx]=idy;
}
bool cmp(edge x,edge y){
	return x.c<y.c;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d %d %d",&n,&m,&k);
	if(k==0){
		long long ans=0;
		for(int i=1;i<=n;i++){
			id[i]=i;
		}
		for(int i=1;i<=m;i++){
			scanf("%d %d %d",&e[i].u,&e[i].v,&e[i].c);
		}
		sort(e+1,e+1+m,cmp);
		for(int i=1;i<=m;i++){
			int u=e[i].u,v=e[i].v,c=e[i].c;
			if(ask(u)==ask(v)){
				continue;
			}
			ans+=c;
			merge(u,v);
		}
		cout<<ans;
	}
	else{
		long long ans=0;
		for(int i=1;i<=n+k;i++){
			id[i]=i;
		}
		for(int i=1;i<=m;i++){
			cin>>e[++cnt].u>>e[cnt].v>>e[cnt].c;
		}
		for(int i=1;i<=k;i++){
			int x;
			cin>>x;
			for(int j=1;j<=n;j++){
				e[++cnt].u=n+i;
				e[cnt].v=j;
				cin>>e[cnt].c;
			}
		}
		sort(e+1,e+1+cnt,cmp);
		for(int i=1;i<=cnt;i++){
			int u=e[i].u,v=e[i].v,c=e[i].c;
			if(ask(u)==ask(v)){
				continue;
			}
			ans+=c;
			merge(u,v);
		}
		cout<<ans;
	}
	return 0;
}
