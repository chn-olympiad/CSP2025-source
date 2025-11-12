#include<bits/stdc++.h>
using namespace std;
struct edge{
	int u,v,w;
};
edge a[1000005];
int fa[10015];
int find(int x){
	if(fa[x]==x){
		return x;
	}
	return fa[x]=find(fa[x]);
}
void merge(int x,int y){
	fa[y]=x;
}
long long n,m,k;
bool cmp(edge x,edge y){
	return x.w<y.w;
}
int num;
int f(){
	int ans=0;
	int cnt=0;
	for(int i=1;i<=m+k*n;i++){
		int u=a[i].u;
		int v=a[i].v;
		int w=a[i].w;
		int fax=find(u);
		int fay=find(v);
		if(fax!=fay){
			merge(fax,fay);
			ans+=w;
			cnt++;
		}
		if(cnt==n-1){
			return ans;
		}
	}
	return 0;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a[i].u>>a[i].v>>a[i].w;
	}
	sort(a+1,a+m+1,cmp);
	for(int i=1;i<=n+k;i++){
		fa[i]=i;
	}
	cout<<f();
	return 0;
}
