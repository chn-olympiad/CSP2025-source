#include<bits/stdc++.h>
using namespace std;
int h[1000005];
int f(int x){
	if(h[x]==x){
		return x;
	}
	h[x]=f(h[x]);
	return h[x];
}
void bi(int x,int y){
	x=f(x);
	y=f(y);
	h[x]=y;
}
bool check(int x,int y){
	return f(x)==f(y);
}
struct node{
	int u,v,w;
}a[1000005];
bool cmp(node b,node c){
	 return b.w<c.w;
}
bool c[1000005];
int cnt[1000005];
int e[1000005];
void s(){
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		h[i]=i;
	}
	for(int i=1;i<=m;i++){
		int x,y,t;
		cin>>x>>y>>t;
		a[i].u=x;
		a[i].v=y;
		a[i].w=t;
	}
	int pos=n;
	for(int i=1;i<=k;i++){
		int z;
		cin>>z;
		cnt[i+n]=z;
		for(int j=1;j<=n;j++){
			cin>>e[j];
			a[++pos]={i+n,j,e[j]+z};
		}
	}
	int nn=m+k*n;
	sort(a+1,a+1+nn,cmp);
	long long ans=0;
	for(int i=1;i<=nn;i++){
		if(check(a[i].u,a[i].v)){
			continue;
		}
		bi(a[i].u,a[i].v);
		ans+=a[i].w;
		if(c[a[i].u]){
			ans-=cnt[a[i].u];
		}
		if(a[i].u>n&&!c[a[i].u]){
			c[a[i].u]=1;
		}
	}
	cout<<ans;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	s();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
