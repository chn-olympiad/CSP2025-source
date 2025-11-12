#include<bits/stdc++.h>
using namespace std;
int n,m,k,ans;
const int N=1e5+5,M=1e6+5,K=10;
struct node{
	int u,v,w;
}arr[N];
int val[K];
int a[K][N];
bool cmp(node a,node b){
	return a.w<b.w;
}
int f[N];
int find(int x){
	if(f[x]==x){
		return x;
	}
	return f[x]=find(f[x]);
}
int main(){
//	freopen("road.in","r",stdin);
//	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	
	for(int i=1;i<=m;i++){
		cin>>arr[i].u>>arr[i].v>>arr[i].w;
	}
	sort(arr+1,arr+m+1,cmp);
	for(int i=1;i<=n;i++){
		f[i]=i;
	}
	for(int i=1;i<=k;i++){
		cin>>val[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	int cnt=0;
	for(int i=1;i<=m&&cnt<(n-1);i++){
		int x=find(arr[i].u);
		int y=find(arr[i].v);
		int z=arr[i].w;
		if(x!=y){
			ans+=z; 
			cnt++;
			arr[cnt]=arr[i];
		}
	}
	if(k<=0){
		cout<<ans;
		return 0;
	}
} 
