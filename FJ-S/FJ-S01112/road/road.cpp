#include<bits/stdc++.h>
using namespace std;
struct q{
   	int u,v,w;
}c[1001000];
int n,m,k;
long long ans;
int a[10010],b[1001000];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>c[i].u>>c[i].v>>b[i];
		a[c[i].u]+=1;
		a[c[i].v]+=1;
	}
	sort(b+1,b+m+1);
	for(int i=1;i<=m;i++){
		ans+=b[i];
	}
	cout<<ans;
	return 0;
}