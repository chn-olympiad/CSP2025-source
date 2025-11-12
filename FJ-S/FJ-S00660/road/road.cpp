#include <bits/stdc++.h>
using namespace std;
int n,m,k,ans;
struct node{
	int a,b,f;
}a[1000000];

bool cmp(node a,node b){
	return a.f < b.f;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a[i].a>>a[i].b>>a[i].f;
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<m;i++){
		ans+=a[i].f;
	}
	cout<<ans;
	return 0;
}
