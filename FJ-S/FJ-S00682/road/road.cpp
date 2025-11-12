#include<bits/stdc++.h>
using namespace std;
int n,m,k,a1[10005],b1[2000005],b2[2000005],p[15],u,v,w;
long long a[10005],b3[2000005],c[15][10005],q[15],s;
void f(int x,int y,int z){
	b1[z]=a1[x];
	a1[x]=z;
	b2[z]=y;
	b3[z]=w;
	cout<<b1[z]<<' '<<b2[z]<<' '<<b3[z]<<'\n';
}
void h(int x){
	cout<<x<<' '<<b2[x]<<' '<<b3[x]<<'\n';
	if(a[b2[x]]==0){
		a[b2[x]]=b3[x];
		if(a1[b2[x]]!=0)h(a1[b2[x]]);
	}
	else if(b3[x]<a[b2[x]])a[b2[x]]=b3[x];
	if(b1[x]!=0)h(b1[x]);
	return;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		f(u,v,i*2-1);
		f(v,u,i*2);
	}
	for(int i=1;i<=k;i++){
		cin>>p[i];
		for(int l=1;l<=n;l++)cin>>c[i][l];
	}
	a[1]=-1;
	h(a1[1]);
	for(int i=1;i<=n;i++)s+=a[i];
	cout<<s+1;
} 
