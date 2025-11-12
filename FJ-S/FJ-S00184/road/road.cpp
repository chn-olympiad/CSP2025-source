#include<bits/stdc++.h>
using namespace std;
int n,m,k,a[10001],l[10001],fa[10001],c;
long long s;
struct bian{
	int u,v,w;
}b[2000001];
bool cmp(bian a,bian b){return a.w<b.w;}
int f(int a){
	if(fa[a]==a)return a;
	return fa[a]=f(fa[a]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=m;i++)scanf("%d%d%d",&b[i].u,&b[i].v,&b[i].w);
	int t1=m;
	for(int j=1;j<=k;j++){
		int t=0;
		scanf("%d",&c);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			if(a[i]==0)l[++t]=i;
		}
		for(int i=1;i<=t;i++)
		    for(int k=1;k<=n;k++)
		    	if(a[k])b[++t1].u=l[i],b[t1].v=k,b[t1].w=a[k];
	}
	sort(b+1,b+t1+1,cmp);
	for(int i=1;i<=t1;i++){
		int u=b[i].u,v=b[i].v,w=b[i].w;
		int u1=f(u),v1=f(v);
		if(u1!=v1)fa[u1]=v1,s+=w;
	}
	printf("%lld",s);
	return 0;
}
