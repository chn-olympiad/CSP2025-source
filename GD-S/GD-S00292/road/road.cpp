//road
#include<bits/stdc++.h>
using namespace std;
long long n,m,k,fa[10007],ans=0;
struct node{
	long long s,t,w;
}e[1000007];
bool cmp(node x,node y){
	return x.w<y.w;
}
long long f(long long x){
	if(x==fa[x]) return x;
	return fa[x]=f(fa[x]);
}
void me(long long x,long long y){
	fa[f(x)]=f(y);
}
void krus(){
	long long sum=0;
    for(int i=1; i<=n; i++) fa[i]=i;
	for(int i=1; i<=m; i++){
		long long x=e[i].s,y=e[i].t;
		if(f(x)!=f(y)){
			ans+=e[i].w;
			me(x,y);
			sum++;
		}
		if(sum==n-1) break;
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1; i<=m; i++){
    	scanf("%lld %lld %lld", &e[i].s,&e[i].t,&e[i].w);
	}
	sort(e+1,e+m+1,cmp);
	krus();
	cout<<ans;
	return 0;
}
