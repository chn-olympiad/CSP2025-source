#include<bits/stdc++.h>
using namespace std;
struct edge{
int u,v,w;
}ro[11111];
bool cmp(edge a,edge b){
    return a.w<b.w;
}
long long ans;
int main(){
	freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int k,m,n;
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=m;i++){
        int uu,vv,ww;
        scanf("%d%d%d",&uu,&vv,&ww);
        ro[i].u=uu,ro[i].v=vv,ro[i].w=ww;
        ro[i].u=vv,ro[i].v=uu,ro[i].w=ww;
    }
    sort(ro+1,ro+1+m,cmp);
    for(int i=1;i<m;i++){
        ans+=ro[i].w;
    }
    cout<<ans;
	return 0;
}
