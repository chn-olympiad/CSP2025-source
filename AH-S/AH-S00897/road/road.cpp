#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,m,k;
struct node{
	int u,v,w;
}a[N];
bool cmp(node a,node b){
	return a.w<b.w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a[i].u>>a[i].v>>a[i].w;
	}
	sort(a+1,a+n+1,cmp);
	long long sum=0;
	for(int i=1;i<n;i++){
		sum+=a[i].w;
	}
	cout<<sum<<"\n";
	return 0;
}
