#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,k;
struct node{
	int u,v,w;
};
node a[1000005];
bool cmp(node a,node b){
	return a.w <b.w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a[i].u >>a[i].v>>a[i].w;
	}
	if(k==0){
		long long ans=0;
		sort(a+1,a+m+1,cmp);
		for(int i=1;i<n;i++){
			ans=ans+a[i].w;
		}
		cout<<ans; 
	}
	
	return 0;
} 
