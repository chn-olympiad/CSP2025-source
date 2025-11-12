#include<bits/stdc++.h>
using namespace std;
int n,m,k;
struct Node{
	long long u,v,w;
}arr[2000005];
bool cmp(Node x,Node y){
	return x.w<y.w;
}
int fa[10005];
int find(int x){
	if(fa[x]==x){
		return x;
	}
	return fa[x]=find(fa[x]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	int cnt=0;
	for(int i=1;i<=m;i++){
		cnt++;
		cin>>arr[cnt].u>>arr[cnt].v>>arr[cnt].w;
	}
	long long ans=0;
	for(int i=1;i<=k;i++){
		int temp;
		cin>>temp;
		for(int j=1;j<=n;j++){
			cnt++;
			arr[cnt].u=i;
			arr[cnt].v=j;
			cin>>arr[cnt].w;
		}
	}
	sort(arr+1,arr+cnt+1,cmp);
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	for(int i=1;i<=cnt;i++){
		int x=find(arr[i].u),y=find(arr[i].v);
		if(x!=y){
			ans+=arr[i].w;
			fa[x]=y;
		}
	}
	cout<<ans;
	return 0;
} 
