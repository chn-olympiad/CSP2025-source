#include<bits/stdc++.h>
#define int long long
using namespace std;
const int M=1e6+1e5+100,N=1e4+100;
int n,m,k;
struct zzz{
	int u,v,w;
}e[M];
int f[N],top;
int find(int x){
	if(f[x]==x){
		return x;
	}
	return f[x]=find(f[x]);
}
bool cmp(zzz x,zzz y){
	return x.w<y.w;
}
int ans=0,cnt;
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n+k;i++)f[i]=i;
	for(int i=1;i<=m;i++)cin>>e[i].u>>e[i].v>>e[i].w;
	top=m;
	for(int i=1;i<=k;i++){
		int a;
		cin>>a;
		for(int j=1;j<=n;j++){
			e[++top].u=n+i;
			e[top].v=j;
			cin>>e[top].w;
		}
	}
	sort(e+1,e+1+top,cmp);
	for(int i=1;i<=top;i++){
		if(find(e[i].u)!=find(e[i].v)){
			f[find(e[i].u)]=find(e[i].v);
			cnt++;
			ans+=e[i].w;
			if(cnt==n+k-1){
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}
