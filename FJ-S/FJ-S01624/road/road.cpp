#include<bits/stdc++.h>
using namespace std;
int n,m,k,u,v,w,fa[100005],l,ans,er;
vector<int>vec[100005]; 
struct sd{
	int x,y,z;
}a[100005];
bool cmp(sd x,sd y){
	return x.z<y.z;
}
int find(int x){
	if(fa[x]!=x){
		return fa[x]=find(fa[x]);
	}
	else{
		return x;
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i = 1;i<=m;i++){
		scanf("%d%d%d",&u,&v,&w);
		a[i].x=u,a[i].y=v,a[i].z=w;
		//vec[u].push_back({v,w});
		//vec[v].push_back({u,w});
	}
	for(int i = 1;i<=k;i++){
		for(int j = 1;j<=n+1;j++){
			scanf("%d",&er);
		}
	}
	if(k!=0){
		cout<<0;
		return 0;
	}
	for(int i = 1;i<=n;i++){
		fa[i]=i;
	}
	sort(a+1,a+m+1,cmp);
	for(int i = 1;i<=m;i++){
		int dx=a[i].x;
		int dy=a[i].y;
		int dz=a[i].z;
		if(find(dx)!=find(dy)){
			fa[dx]=dy;
			l++;
			ans+=dz;
			if(l==n-1){
				cout<<ans;
				return 0;
			}
		}
	}
}
