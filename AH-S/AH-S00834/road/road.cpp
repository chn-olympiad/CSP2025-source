#include<bits/stdc++.h>
using namespace std;
int n,m,k,j,cnt,ans,fa[1024],chen[15];
int f[15];
struct road{
	int u,v,w,gz;
}r[1000005];
bool cmp(road x,road y){
	return x.w<y.w;
}
int find(int x){
	if(fa[x]==x){
		return x;
	}
	return fa[x]=find(fa[x]);
}
bool merge(int x,int y){
	x=find(x);
	y=find(y);
	if(x==y){
		return false;
	}
	fa[y]=x;
	return true;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		++cnt;
		cin>>r[cnt].u>>r[cnt].v>>r[cnt].w;
		r[cnt].gz=0;
	}
	for(int i=1;i<=k;i++){
		cin>>j;
		chen[i]=j;
		bool flag=0;
		if(j==0){
			flag=1;
		}
		for(int x=1;x<=n;x++){
			int a;
			cin>>a;
			r[++cnt].u=n+i;
			r[cnt].v=x;
			r[cnt].w=a+j;
			if(a){
				flag=0;
			}
		}
		if(flag){
			cout<<0;
			return 0;
		}
	}
	sort(r+1,r+cnt+1,cmp);
	for(int i=1;i<=n+k;i++){
		fa[i]=i;
	}
	if(k==0){
		for(int i=1;i<=cnt;i++){
			if(merge(r[i].u,r[i].v)){
				ans+=r[i].w;
			}
		}
		cout<<ans;
	}
	for(int i=1;i<=cnt;i++){
		if(merge(r[i].u,r[i].v)){
			ans+=r[i].w;
			if(r[i].u-n>0){
				if(f[r[i].u-n]){
					ans-=chen[r[i].u-n];
				}
				f[r[i].u-n]++;
			}
		}
	}
	for(int i=1;i<=k;i++){
		if(f[k]==1){
			ans-=chen[k];
		}
	}
	cout<<ans;
	return 0;
}
