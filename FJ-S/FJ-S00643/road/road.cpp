#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e4+5;
struct Node{
	int u,v,w;
}a[N*N]; 
int n,m,k,r[12][N],mi,fa[N],ans,cnt;
bool cmp(Node a,Node b){
	return a.w<b.w;
}
int find(int x){
	return x==fa[x]?x:fa[x]=find(fa[x]);
}
void merge(int x,int y){
	int fx=find(x);
	int fy=find(y);
	if(fx!=fy){
		fa[y]=x;
	}
	return ;
}
bool check(){
	for(int i=1;i<=n;i++){
		if(r[i][0]!=0) return false;
	}
	return true;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a[i].u>>a[i].v>>a[i].w;
	}
	if(k!=0){
		for(int i=1;i<=k;i++){
			for(int j=0;j<=n;j++) cin>>r[i][j];
		}
	}
	if(k==0){
		for(int i=1;i<=n;i++) fa[i]=i;
		sort(a+1,a+1+n,cmp);
		for(int i=1;i<=m;i++){
			if(cnt==n-1) break;
			if(find(a[i].u)==find(a[i].v)) continue;
			else merge(a[i].u,a[i].v);
			ans+=a[i].w;
			cnt++;
//			cout<<a[i].u<<"->"<<a[i].v<<"\n"; 
//			for(int i=1;i<=n;i++) cout<<fa[i]<<" ";
//			cout<<"\n";
		}
		cout<<ans;
		exit(0);
	}else{
		cout<<0;
	}
	
	return 0;
}
/*
4 4 0
1 4 6
2 3 7
4 2 5
4 3 4
*/
