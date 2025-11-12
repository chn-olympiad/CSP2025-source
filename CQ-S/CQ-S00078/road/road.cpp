#include<bits/stdc++.h>
using namespace std;
int n,m,k;
struct node{
	int u,v,w;
}a[1000010];
int f[1000010];
bool cmp(node x,node y){
	return x.w<y.w;
}
int find(int x){
	if(f[x]!=x) return f[x]=find(f[x]);
	return f[x];
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a[i].u>>a[i].v>>a[i].w;
	}
	sort(a+1,a+1+m,cmp);	
	for(int i=1;i<=n;i++){
		f[i]=i;
	}
	int ans=0,cnt=0;
	for(int i=1;i<=m;i++){
		int u=find(a[i].u),v=find(a[i].v);
		if(u!=v){
			f[v]=u;
			ans+=a[i].w;
			cnt++;
		}
		if(cnt==n-1){
			break;
		}
	}
	cout<<ans;
	return 0;
} 
