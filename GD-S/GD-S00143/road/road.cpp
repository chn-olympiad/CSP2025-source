#include <bits/stdc++.h>
using namespace std;
long long n,m,k,f[10005],c[10005],Cnt=0,Tot=0;
long long Ans=0;
bool bo1=0;
struct Node{
	long long u,v;
	long long w;
	bool operator < (Node x)const{return w<x.w;}
}s[2000005]; 
long long find(long long u){
	if(f[u]==u) return u;
	f[u]=find(f[u]);
	return f[u];
}
void Merge(long long u,long long v){
	f[find(u)]=find(v);
	return;
}
bool check(long long u,long long v){
	if(find(u)==find(v)) return true;
	return false;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(long long i=1;i<=m;i++){
		Cnt++;
		scanf("%lld%lld%lld",&s[Cnt].u,&s[Cnt].v,&s[Cnt].w);
	}
	for(long long i=1;i<=n;i++) f[i]=i;
	if(k==0){
		sort(s+1,s+m+1);
		for(long long i=1;i<=m&&Tot!=n-1;i++){
			long long u=s[i].u,v=s[i].v;
			long long w=s[i].w;
			if(check(u,v)) continue;
			Ans+=w;
			Merge(u,v);
			Tot++;
		}
		printf("%lld",Ans);
		return 0;
	}
	for(long long i=1;i<=k;i++){
		scanf("%lld",&c[i]);
		bo1=(bo1||c[i]);
		bool bo2=1;
		for(long long j=1;j<=n;j++){
			Cnt++;
			s[Cnt].u=i;
			s[Cnt].v=j;
			scanf("%lld",&s[Cnt].w);
			bo2=(bo2&&s[Cnt].w);
		}
		bo1=(bo1||bo2);
	}
	if(!bo1){
		sort(s+1,s+Cnt+1);
		for(long long i=1;i<=Cnt&&Tot!=n-1;i++){
			long long u=s[i].u,v=s[i].v;
			if(check(u,v)) continue;
			long long w=s[i].w;
			Ans+=w;
			Merge(u,v);
			Tot++;
		}
		printf("%lld",Ans);
		//for(long long i=1;i<n;i++) if(check(i,i+1)==false) cout<<"!";
	}
	return 0;
}
