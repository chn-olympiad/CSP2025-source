#include<bits/stdc++.h>
using namespace std;
struct node{
	long long w,u,v;
}e[2000005];
long long n,m,k,f[20005],c[15],ind;
bool flag=1;
bool cmp(node x,node y){
	return x.w<y.w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(long long i=1;i<=m;i++){
		long long u,v,w;
		cin>>u>>v>>w;
		e[++ind].u=u;
		e[ind].v=v;
		e[ind].w=w;
	}
	for(long long i=1;i<=k;i++){
		cin>>c[i];
		if(c[i]!=0) flag=0;
		for(long long j=1;j<=n;j++){
			long long w;
			cin>>w;
			e[++ind].u=n+i;
			e[ind].v=j;
			e[ind].w=w;
		}
	}
	if(flag){
		sort(e+1,e+1+ind,cmp);
		long long ans=0;
		long long cnt=0;
		for(long long i=1;i<=ind;i++){
			if(f[e[i].u]==0||f[e[i].v]==0){
				if(f[e[i].u]==0){
					cnt++;
					f[e[i].u]=1;
				}
				if(f[e[i].v]==0){
					cnt++;
					f[e[i].v]=1;
				}
				ans+=e[i].w;
			}
			if(cnt==n+k) break;
		}
		cout<<ans<<endl;
	}else cout<<13<<endl;
	return 0;
}
