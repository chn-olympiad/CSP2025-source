//GZ-S00259 遵义市第四中学 杨子腾 
#include<bits/stdc++.h>
using namespace std;
struct info{
	int u,v;
	long long w;
};
bool cmp(const info&a,const info&b){
	return a.w<b.w;
}
vector<info> e;
int p[10000][10000],f[10000],c[10],a[10][10000],n,q[10000][10000];
int find(int x){
	return f[x]==x?x:f[x]=find(f[x]);
}
void build(int i){
	for(int j=1;j<n;j++)for(int k=0;k<j;k++)
		if(p[j][k])p[j][k]=p[k][j]=min(p[j][k],a[i][j]+a[i][k]+1);
		else p[j][k]=p[k][j]=a[i][j]+a[i][k]+1;
}
long long calc(){
	for(int i=1;i<n;i++)for(int j=0;j<i;j++)if(p[i][j])
		e.push_back({i,j,p[i][j]-1});
	sort(e.begin(),e.end(),cmp);
	int t=n;
	long long s=0;
	for(auto i:e){
		int x=find(i.u),y=find(i.v);
		if(x!=y)t--,f[x]=y,s+=i.w;
		if(!t)break;
	}
	return s;
}
#define gc getchar()
void read(int& x){
	x=0;
	char c=gc;
	while(!isdigit(c))c=gc;
	while(isdigit(c))x=(x<<3)+(x<<1)+c-'0',c=gc;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int m,k;
	long long ans=1ll<<60;
	scanf("%d%d%d",&n,&m,&k);
	while(m--){
		int u,v,w;
		read(u),read(v),read(w),u--,v--,q[u][v]=q[v][u]=w+1;
	}
	for(int i=0;i<k;i++){
		read(c[i]),m=max(m,c[i]);
		for(int j=0;j<n;j++)read(a[i][j]);
	}
	if(!m){
		for(int i=0;i<n;i++)f[i]=i;
		for(int i=1;i<n;i++)for(int j=0;j<i;j++)p[i][j]=p[j][i]=q[i][j];
		for(int i=0;i<k;i++)build(i);
		printf("%lld",calc());
		return 0;
	}
	for(int i=0;i<1<<k;i++){
		for(int i=0;i<n;i++)f[i]=i;
		for(int j=1;j<n;j++)for(int k=0;k<j;k++)p[j][k]=p[k][j]=q[j][k];
		int cnt=0;
		for(int j=0;j<k;j++)if(i>>j&1){
			cnt+=c[j];
			build(j);
		}		
		ans=min(ans,calc()+cnt);
	}
	printf("%lld",ans);
	return 0;
}
