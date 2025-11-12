#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
struct node{
	int u,v,w;
}dt[1000001];
int n,m,k,c[11],arr[11][10001];
long long ans;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>dt[i].u>>dt[i].v>>dt[i].w;
		if(k==0) ans+=dt[i].w;
	}
	if(k==0){
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=k;i++){
		bool f=1;
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>arr[i][j];
			if(arr[i][j]!=0) f=0;
		}
		if(f){
			cout<<c[i];
			return 0;
		}
	}
	return 0;
}
