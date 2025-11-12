#include<bits/stdc++.h>
using namespace std;
int fa[10005];
struct s{
	long long u,v,w;
}b[1000005];
long long c[20][10005];
long long n,m,k,ans=4611686018427387904,l,cnt;
bool cmp(s x,s y){
	return x.w<y.w;
}
int f(int x){
	if(fa[x]==x){
		return x;
	}
	fa[x]=f(fa[x]);
	return fa[x];
}
int kr(int d){
	long long cnt2=0;
	s t[1000005];
	for(int i=1;i<=l;i++){
		t[i].u=b[i].u;
		t[i].v=b[i].v;
		t[i].w=b[i].w;
	}
	for(int i=1;i<=n+d;i++){
		fa[i]=i;
	}
	sort(t+1,t+l+1,cmp);
	//for(int i=1;i<=l;i++)
	for(int i=1;i<=l;i++){
		if(f(t[i].u)!=f(t[i].v)){
			fa[f(t[i].u)]=f(t[i].v);
			//cout<<t[i].u<<fa[t[i].u]<<' '<<t[i].v<<fa[t[i].v]<<'/';			
			cnt2+=t[i].w;
		}
	}
	return cnt2;
}
void dfs(int d){
	if(d==k+1){
		//cout<<kr(d)<<"/";
		ans=min(kr(d-1)+cnt,ans);
		return;
	}
	dfs(d+1);
	for(int i=l+1;i<=l+n;i++){
		b[i].u=n+d;
		b[i].v=i-l;
		b[i].w=c[d][i-l];
	}
	cnt+=c[d][0];
	l+=n;
	dfs(d+1);
	l-=n;
	cnt-=c[d][0];
	return;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	l=m;
	for(int i=1;i<=n+k;i++){
		fa[i]=i;
	}
	for(int i=1;i<=m;i++){
		cin>>b[i].u>>b[i].v>>b[i].w;
	}
	for(int i=1;i<=k;i++){
		for(int j=0;j<=n;j++){
			cin>>c[i][j];
		}
	}
	dfs(1);
	cout<<ans;
	return 0;
}
