#include<bits/stdc++.h>
using namespace std;
long long n,m,k;
long long u,v,w;
long long ans;
struct node{
	long long now,nxt,s;
};
node tr[1000001];
long long c[11],a[1001][11];
long long d[1001][1001];
int cmp(node l,node r){
	return l.s<r.s;
}
long long fa[1001];
long long find(long long now){
	if(fa[now]==now){
		return now;
	}
	fa[now]=find(fa[now]);
	return fa[now];
}
void merge(long long l,long long r){
	long long fl=find(l),fr=find(r);
	fa[fr]=fl;
	return ;
}
void bt(){
	sort(tr+1,tr+1+m,cmp);
	for(int i=1;i<=m;i++){
		long long l=tr[i].now,r=tr[i].nxt;
		if(find(l)!=find(r)){
			merge(l,r);
			ans+=tr[i].s;
		}
	}
	return;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		tr[i]={u,v,w};
	}
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	bt();
	if(k==0){
		cout<<ans;
		return 0; 
	}
	
	return 0;
}