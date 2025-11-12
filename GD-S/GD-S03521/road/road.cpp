#include<bits/stdc++.h>
using namespace std;
int ans,n,m,k,v[10010],t=0,xx[55][10010],ka[55]={},vj[55];
struct stu{
	int u,v,w,h=0;
}r[2000100];
bool cmp(stu pre,stu nxt){
	return pre.w+ka[nxt.h]<nxt.w+ka[nxt.h];
}
int f(int x){
	return v[v[x]]==v[x]?v[x]:f(v[x]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)v[i]=i;
	for(int i=1;i<=m;i++){
		cin>>r[i].u>>r[i].v>>r[i].w;
	}
	for(int i=1;i<=k;i++){
		cin>>ka[i];
		for(int j=1;j<=n;j++)cin>>xx[i][j];
		for(int j=1;j<n;j++){
			for(int z=j+1;z<=n;z++){
				m++;r[m].u=j;r[m].v=z;r[m].w=xx[i][j]+xx[i][z];r[m].h=i;
			}
		}
	}
	sort(r+1,r+1+m,cmp);
	for(int i=1;i<=m;i++){
		v[r[i].u]=f(r[i].u);v[r[i].v]=f(r[i].v);
		if(v[r[i].u]!=v[r[i].v]){
		v[v[r[i].u]]=v[r[i].v];t++;ans+=r[i].w;
		if(r[i].h!=0){
			if(vj[r[i].h]==0){
				ans+=ka[r[i].h];vj[r[i].h]=1;
			}
		}
		}
		if(t==n-1)break;
	}
	cout<<ans;
	return 0;
}
