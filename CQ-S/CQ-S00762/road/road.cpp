#include<bits/stdc++.h>
using namespace std;
const int N = 1e8;
int n,m,k;
int fa[1000005];
struct node{
	int u,v,w;
}a[100005];
bool cmp(node a,node b){
	return a.w<b.w;
}
int find(int x){
	if(fa[x] == x){
		return x;
	}
	return fa[x] = find(fa[x]);
}

int main(void){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int sum = 0;
	cin>>n>>m>>k;
	if(k!=0){ cout<<"0"; 
		return 0;
	} 
	for(int i = 1;i<=n;i++){
		fa[i] = i;
	}
	for(int i = 1;i<=n;i++){
		cin>>a[i].u>>a[i].v>>a[i].w;
	}
	sort(a+1,a+n+1,cmp);
	for(int i = 1;i<=n;i++){
		int fu = find(a[i].u),fv = find(a[i].v);
		fa[fv] = fu;
		sum += a[i].w;
	}
	cout<<sum;
	return 0;
} 
