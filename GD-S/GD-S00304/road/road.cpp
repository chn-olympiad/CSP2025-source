#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=10005;
int father[N],c[13][N],num[13],s[13],n,m,k,ans,ans1=INT_MAX,cnt;
struct zsy{
	int u;
	int v;
	int w;
}a[1001000],b[1001000];
bool cmp(zsy aaa,zsy bbb){
	return aaa.w<bbb.w;
}int find(int x){
	if(father[x]!=x) father[x]=find(father[x]);
	return father[x];
}void dfs(int x,int y){
	if(x>k){
		cnt=ans=0;
		for(int i=1;i<=y;i++){
			ans+=num[s[i]];
			for(int j=1;j<=n;j++){
				++cnt;
				b[cnt].u=s[i]+n,b[cnt].v=j,b[cnt].w=c[s[i]][j];
			}
		}sort(b+1,b+n*y+1,cmp);
		for(int i=1;i<=n+k;i++) father[i]=i;
		for(int i=1,la=1,lb=1;i<=n+y-1;i++){
			if(ans>ans1) return;
			while(la<=m&&find(a[la].u)==find(a[la].v)) la++;
			while(lb<=n*y&&find(b[lb].u)==find(b[lb].v)) lb++;
			if(lb>n*y||(la<=m&&a[la].w<b[lb].w)) father[find(a[la].u)]=find(a[la].v),ans+=a[la].w,la++;
			else father[find(b[lb].u)]=find(b[lb].v),ans+=b[lb].w,lb++;
		}ans1=min(ans,ans1);
	}else{
		dfs(x+1,y);
		s[y+1]=x;
		dfs(x+1,y+1);
	}
}signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=m;++i) scanf("%lld%lld%lld",&a[i].u,&a[i].v,&a[i].w);
	sort(a+1,a+m+1,cmp);
	for(int i=1;i<=k;++i){
		scanf("%lld",&num[i]);
		for(int j=1;j<=n;++j) scanf("%lld",&c[i][j]);
	}dfs(1,0);
	cout<<ans1;
	return 0;
}
