#include<bits/stdc++.h>
using namespace std;
struct node{
	int x,y;
	int w;
}a[1000005];
int n,m,k;
bool cmp(node x,node y){
	return x.w<y.w;
}
int fa[10005];
int find(int x){
	if(fa[x]==x)return x;
	else return fa[x]=find(fa[x]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	if(k!=0){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=m;i++){ 
		cin>>a[i].x>>a[i].y>>a[i].w;
	}
	sort(a+1,a+m+1,cmp);
	for(int i=1;i<=n;i++)fa[i]=i;
	long long ans=0;
	for(int i=1;i<=n;i++){
		int x=a[i].x,y=a[i].y,w=a[i].w;
		if(find(x)!=find(y)){
			ans+=w;
			fa[find(y)]=x;
		}
	}
	cout<<ans;
	return 0;
	
}
