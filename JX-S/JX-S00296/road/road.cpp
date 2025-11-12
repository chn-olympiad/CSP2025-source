#include<bits/stdc++.h>
using namespace std;
int sum,n,m,k;
struct l{
	int u,v,w;
}a[1000005];
bool cmp(l a,l b){
	return a.w<b.w;
}
void dfs(){
	for(int i=1;i<=m;i++){
		sum+=a[i].w;
	}
}
int main(){
	//freopen("road.in","r",stdin);
	//freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a[i].u>>a[i].v>>a[i].w;
	}
	sort(a+1,a+m+1,cmp);
	dfs();
	cout<<sum;
	return 0;
}

