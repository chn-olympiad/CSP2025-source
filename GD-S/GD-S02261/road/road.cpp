#include<bits/stdc++.h>
using namespace std; 
#define N 1000004
struct NOIP{
	int u,v,z;
}x[N];
bool cmp(NOIP i,NOIP j){
	return i.z<j.z;
}
int f[N];
int n,m,j,l,sum,ll[15][N];
int find(int k){
	if(f[k]==k)return f[k];
	return f[k]=find(f[k]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>l;
	for(int i=1;i<=m;i++){
		cin>>x[i].u>>x[i].v>>x[i].z;
	}
	for(int i=1;i<=l;i++){
		for(j=1;j<=n;j++)cin>>ll[i][j];
	}
	for(int i=1;i<=n;i++)f[i]=i;
	sort(x+1,x+1+n,cmp);
	for(int i=1;i<=n;i++){
		int u=x[i].u;
		int v=x[i].v;
		int z=x[i].z;
		u=find(u);
		v=find(v);
		if(u!=v){
			f[u]=v;
			sum+=z;
		}
	}
	cout<<sum;
	return 0;
 } 
