#include<bits/stdc++.h>
using namespace std;
int n,m,k;
struct graph{
	int x,y,z;
	inline bool operator<(graph &A)const{
		return z<A.z;
	}
}a[2000010];
int c[15][20010];
int ans;
int f[20010],tot;

inline int find(int x){
	return x==f[x]?x:f[x]=find(f[x]);
}
inline void Kruskal(){
	int p=0;
	for(int i=1;i<=tot;i++){
		if(p==n+k-1)return;
		
		int x=find(a[i].x),y=find(a[i].y);
		if(x!=y){
//			cout<<a[i].x<<' '<<a[i].y<<' '<<a[i].z<<endl;
			f[x]=y;
			p++;
			ans+=a[i].z;
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
//	printf("!");
	scanf("%d%d%d",&n,&m,&k);
	
	for(int i=1;i<=n+k+1;i++)f[i]=i;
	
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
//		cout<<a[i].x<<' '<<a[i].y<<' '<<a[i].z<<'\n';
		
	}
	tot=m;
	for(int i=1;i<=k;i++){
		for(int j=0;j<=n;j++){
			scanf("%d",&c[i][j]);
			if(j>0){
				a[++tot].x=n+i;
				a[tot].y=j;
				a[tot].z=c[i][j];
			}
		}
	}
	sort(a+1,a+tot+1);
	Kruskal();
	printf("%d",ans);
	return 0;
}
