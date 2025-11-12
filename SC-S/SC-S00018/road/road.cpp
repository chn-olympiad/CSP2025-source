#include<bits/stdc++.h>
using namespace std;
int n,m,k;
struct node{
	int u,v,w;
}city[1000010];
int a[1000010];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	if(k==0){
		int ans=0;
		for(int i=1;i<=m;i++){
			cin>>city[i].u>>city[i].v>>city[i].w;
			ans+=city[i].w;
		}
		cout<<ans;
	}
	return 0;
}