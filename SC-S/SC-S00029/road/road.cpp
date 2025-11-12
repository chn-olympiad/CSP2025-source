#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5,M=1e6+5;
struct node{
	int x,y,z;
}a[M];
int n,m,k,fa[N],ans;
bool cmp(node q,node w){
	return q.z<w.z;
}
int find(int x){
	if(x!=fa[x]) fa[x]=find(fa[x]);
	return fa[x];
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a[i].x>>a[i].y>>a[i].z;
	}
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	sort(a+1,a+m+1,cmp);
	for(int i=1;i<=m;i++){
	    int rx=find(a[i].x),ry=find(a[i].y);
		if(rx!=ry){
			fa[rx]=fa[ry];
			ans+=a[i].z;
		}
	}
	cout<<ans;
	return 0;
}