#include<bits/stdc++.h>
using namespace std;
long long n,m,k,cnt,maxn,fa[20004],sum=0x3f3f3f3f,x[100];
bool vis[20004],kkk;
struct str{
	int u,v,w;
}road[2000006];
bool cmp(str x,str y){
	return x.w<y.w;
}
int find(int x){
	if(x!=fa[x]){
		x=find(fa[x]);
	}
	return x;
}
void add(int x,int y){
	int fax=find(x),fay=find(y);
	if(fax!=fay){
		fa[fax]=fay;
	}
	return ;
}
bool check(){
	for(int i=2;i<=n;i++){
		if(find(i)!=find(i-1)){
			return false;
		}
	}
	return true;
}
void bellman(){
	memset(vis,0,sizeof(vis));
	maxn=0;
	for(int i=1;i<=cnt;i++){
		if(check()) return ;
		int u=road[i].u,v=road[i].v,w=road[i].w;
		if(find(u)!=find(v)){
			add(u,v);
			maxn+=w;
			vis[u]=vis[v]=1;
		}
	}
	return ;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		cnt++;
		road[cnt].u=u;
		road[cnt].v=v;
		road[cnt].w=w;
	}
	sort(road+1,road+1+cnt,cmp);
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	bellman();
	sum=maxn;
	for(int i=1;i<=k;i++){
		int y;
		cin>>x[i];
		kkk=0;
		for(int j=1;j<=n;j++){
			cin>>y;
			if(y!=0){
				kkk=1;
			}
			cnt++;
			road[cnt].u=n+i;
			road[cnt].v=j;
			road[cnt].w=y;
		}
		if(kkk==0){
			cout<<0;
			return 0;
		}
		sort(road+1,road+1+cnt,cmp);
		for(int j=1;j<=n+i;j++){
			fa[j]=j;
		}
		bellman();
		for(int j=1;j<=i;j++){
			if(vis[n+j]==1){
				maxn+=x[j];
			}
		}
		sum=min(sum,maxn);
	}
	cout<<sum;
    return 0;
}
