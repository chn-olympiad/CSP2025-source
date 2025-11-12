#include<bits/stdc++.h>
using namespace std;
struct tt{
	long long x,y,z,con;
}a[11000005];
int n,m,contryside,f[10005],vis[15],b[10005],z[15];
long long ans,a1;
bool cmp(tt l,tt r){
	return l.z<r.z;
}
int find(int x){
	if(f[x]==x) return x;
	return f[x]=find(f[x]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>contryside;a1=m;
	for(int i=1;i<=n;i++) f[i]=i;
	for(int i=1;i<=m;i++) cin>>a[i].x>>a[i].y>>a[i].z;
	for(int i=1;i<=contryside;i++){
		cin>>z[i];
		for(int j=1;j<=n;j++) cin>>b[j];
		for(int j=1;j<=n;j++) for(int k=j+1;k<=n;k++) a[++a1]={j,k,b[k]+b[j],i};
	}
	sort(a+1,a+1+a1,cmp);
	for(int i=1;i<=a1;i++){
		int x1=find(a[i].x),y1=find(a[i].y);
		if(x1!=y1){
			ans+=a[i].z,f[y1]=x1;
			if(vis[a[i].con]==0&&a[i].con!=0) vis[a[i].con]=1,ans+=z[a[i].con];
		}
	}
	cout<<ans;
	return 0;
} 
