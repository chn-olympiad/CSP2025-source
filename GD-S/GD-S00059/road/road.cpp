#include<bits/stdc++.h>
#define elif else if
//#define int long long
using namespace std;
int n,m,k,v[114514*10],aa[114514*10],ans;
struct node{
	int u,v,w;
}q[114514*10];
bool cmp(int a,int b){
	return q[a].w>q[b].w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;for(int i=0;i<m;i++) cin>>q[i].u>>q[i].v>>q[i].w,aa[i]=i;
	sort(aa,aa+m,cmp);
	v[q[0].u]=1;
	for(int i=0;i<m;i++) if(v[q[aa[i]].u]+v[q[aa[i]].v]==1) v[q[aa[i]].u]=v[q[aa[i]].v]=1,ans+=q[aa[i]].w;
	cout<<ans;
	return 0;
}
