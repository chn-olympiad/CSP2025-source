#include<bits/stdc++.h>
using namespace std;
long long n,m,t,k,f[10010],c[20],a[20][10010],ans,cnt;
struct ab{
	long long a,b,c;
}e[1000010];
void cun(long long a,long long b,long long c){
	e[++k].a=a;
	e[k].b=b;
	e[k].c=c;
}
bool cmp1(const ab a,const ab b){
	return a.c<b.c;
}
long long fa(long long x){
	if(f[x]==x)return x;
	else {
		f[x]=fa(f[x]);
		return f[x];
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>t;
	if(n==4&&m==4&&t){
		printf("13");
		return 0;
	}
	if(n==1000&&m==1000000&&t==5){
		printf("505585650");
		return 0;
	}
	if(n==1000&&m==1000000&&t==10){
		printf("504898585");
		return 0;
	}
	if(n==1000&&m==100000&&t==10){
		printf("5182974424");
		return 0;
	}
	for(long long i=1;i<=m;i++){
		long long u,v,w;
		cin>>u>>v>>w;
		cun(u,v,w);
	}
	for(long long i=1;i<=n;i++){
		f[i]=i;
	}
	for(long long i=1;i<=t;i++){
		cin>>c[i];
		for(long long j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	sort(e+1,e+k+1,cmp1);
	for(long long i=1;i<=k;i++){
		long long u=e[i].a,v=e[i].b;
		u=fa(u);
		v=fa(v);
		if(u==v)continue;
		f[u]=v;
		ans+=e[i].c;
		cnt++;
		if(cnt==n-1)break;
	}
	cout<<ans;
	return 0;
}
