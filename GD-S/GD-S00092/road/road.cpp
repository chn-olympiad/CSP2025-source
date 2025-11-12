#include<bits/stdc++.h>
using namespace std;
long long n,m,k,fa[10010];
long long c[20][1010];
long long e[1010][1010];
long long fd(long long x){
	if(fa[x]==x){
		return x;
	}
	return fa[x]=fd(fa[x]);
}
void me(long long x,long long y){
	if(fd(x)!=fd(y)){
		fa[fd(x)]=fd(y);
	}
}
long long ans=0;
struct node{
	long long l,r,w;
}tr[6000010];
bool cmp(node x,node y){
	return x.w<y.w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			e[i][j]=-1;
		}
	}
	for(long long i=1;i<=n;i++){
		fa[i]=i;
	}
for(long long i=1;i<=m;i++){
	scanf("%lld%lld%lld",&tr[i].l,&tr[i].r,&tr[i].w);
}
for(long long i=1;i<=k;i++){
	scanf("%lld",&c[i][0]);
	for(long long j=1;j<=n;j++){
		scanf("%lld",&c[i][j]);
	}
}
for(int p=1;p<=k;p++){
for(long long i=1;i<=n;i++){
	for(long long j=1;j<i;j++){
		if(e[i][j]==-1){
			e[i][j]=c[p][i]+c[p][j];
		}
		else{
			e[i][j]=min(c[p][i]+c[p][j],e[i][j]);
		}
	}
}
}
for(int i=1;i<=n;i++){
	for(int j=1;j<=n;j++){
		if(e[i][j]!=-1){
			tr[++m].w=e[i][j];
			tr[m].l=i;
			tr[m].r=j;
		}
	}
}
//cout<<m<<"\n";
sort(tr+1,tr+1+m,cmp);
//for(int i=1;i<=100;i++){
//	cout<<tr[i].l<<" "<<tr[i].r<<" "<<tr[i].w<<"\n";
//}
for(long long i=1;i<=m;i++){
	if(fd(tr[i].l)!=fd(tr[i].r)){
		me(tr[i].l,tr[i].r);
		ans+=tr[i].w;
	}
}
cout<<ans;
	return 0;
} 
