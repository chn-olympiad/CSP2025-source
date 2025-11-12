#include<bits/stdc++.h>
using namespace std;
const int N = 1e4+5;
const int M = 1e6+5; 
int m,n,k;
struct node{
	int u,v,w;
}a[M];
bool cmp(node x,node y){
	return x.w<y.w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>m>>n>>k;
	for(int i=1;i<=m;i++){
		cin>>a[i].u>>a[i].v>>a[i].w;
	}
	sort(a+1,a+n+1,cmp);
	int ans=0;
	for(int i=1;i<n;i++){
		ans+=a[i].w;
	}
	cout<<ans;
	return 0;
}

