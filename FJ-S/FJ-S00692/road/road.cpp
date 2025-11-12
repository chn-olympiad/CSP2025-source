#include<bits/stdc++.h>
using namespace std;
int n,m,k,a[12][10002],f[10002],c[12],d[1002][1002];
struct ro{
	int u,v,w;
	bool operator<(ro x){
		return w<x.w;
	}
};
long long ans;
vector<ro>s;
int find(int x){
	if(f[x]==x)return x;
	return f[x]=find(f[x]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	s.resize(m),memset(d,0x3f,sizeof d);
	for(int i=1;i<=n;i++)f[i]=i;
	for(int i=0;i<m;i++)scanf("%d%d%d",&s[i].u,&s[i].v,&s[i].w),d[s[i].u][s[i].v]=d[s[i].v][s[i].u]=s[i].w;
	for(int i=1;i<=k;i++){
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++)scanf("%d",&a[i][j]);
		for(int j=1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				if(a[i][j]+a[i][k]<d[j][k])s.push_back({j,k,a[i][j]+a[i][k]}),d[j][k]=d[k][j]=a[i][j]+a[i][k];
			}
		}
	}
	sort(s.begin(),s.end());
	for(ro x:s){
		int fu=find(x.u),fv=find(x.v);
		if(fu!=fv)ans+=x.w,f[fu]=fv,n--;
		if(n==1)break;
	}
	cout<<ans;
	return 0;
}
