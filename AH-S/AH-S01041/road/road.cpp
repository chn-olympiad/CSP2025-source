#include<bits/stdc++.h>
using namespace std;
int n,m,k;
struct nd{
	int x,y,z;
}a[1100005];
int fa[1100005];
int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
struct cy{
	int w,cost[10005];
}f[15];
bool cmp(nd k1,nd k2){
	return k1.z<k2.z;
}
int ans,sum,fg=1;
int b[1100005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
	}
	for(int i=1;i<=k;i++){
		scanf("%d",&f[i].w);
		if(f[i].w!=0) fg=0;
		for(int j=1;j<=n;j++){
			scanf("%d",&f[i].cost[j]);
		}
	}
	if(k<=0){
		for(int i=1;i<=n;i++) fa[i]=i;
		sort(a+1,a+m+1,cmp);
		for(int i=1;i<=m;i++){
			int e1=find(a[i].x),e2=find(a[i].y);
			if(e1==e2) continue;
			fa[e1]=e2;
			ans+=a[i].z;
			sum++;
			if(sum==n-1){
				cout<<ans<<endl;
				return 0;
			}
		}
	}
	if(fg){
		int pos=m+1;
		for(int i=1;i<=k;i++){
			for(int j=1;j<=n;j++){
				a[pos].x=i+n,a[pos].y=j,a[pos].z=f[i].cost[j];
				pos++;
			}
		}
		for(int i=1;i<=n+pos+1;i++) fa[i]=i;
		sort(a+1,a+pos,cmp);
		for(int i=1;i<=m+pos;i++){
			int e1=find(a[i].x),e2=find(a[i].y);
			if(e1==e2) continue;
			fa[e1]=e2;
			ans+=a[i].z;
			sum++;
			if(sum==n+k-1){
				cout<<ans<<endl;
				return 0;
			}
		}		
	}
	return 0;
}
