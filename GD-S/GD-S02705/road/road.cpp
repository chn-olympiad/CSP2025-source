#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,k,cnte,ans;
bool flag=1;
int c[15],a[15][10005];
struct edge{
	int nex,to,val;
}
e[2000005];
bool cmp(edge x,edge y){
	return x.val<y.val;
}
int fa[10005];
int find1(int x){
	if(fa[x]!=x) fa[x]=find1(fa[x]);
	return fa[x];
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	int u,v,w;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		e[++cnte].nex=u;
		e[cnte].to=v;
		e[cnte].val=w;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		if(c[i]!=0) flag=0;
		for(int j=1;j<=n;j++) cin>>a[i][j];
	}
	if(k==0){
		for(int i=1;i<=n;i++) fa[i]=i;
		sort(e+1,e+cnte+1,cmp);
		for(int i=1;i<=m;i++){
			if(find1(e[i].nex)==find1(e[i].to)) continue;
			ans+=e[i].val;
			fa[find1(e[i].nex)]=find1(e[i].to);
		}
		cout<<ans<<endl;
	}
	if(flag==1){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=k;j++){
				//if(a[j][i]==0){
					for(int l=1;l<=n;l++){
						if(i==l) continue;
						e[++cnte].nex=i;
						e[cnte].to=l;
						e[cnte].val=a[j][l]+a[j][i];
					}
				//}
			}
		}
		for(int i=1;i<=n;i++) fa[i]=i;
		sort(e+1,e+cnte+1,cmp);
		for(int i=1;i<=m;i++){
			if(find1(e[i].nex)==find1(e[i].to)) continue;
			ans+=e[i].val;
			fa[find1(e[i].nex)]=find1(e[i].to);
		}
		cout<<ans<<endl;
	}
	return 0;
}
