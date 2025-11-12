#include<bits/stdc++.h>
using namespace std;
struct r{int u,v,w;}e[1000005];
bool cmp(r x,r y){return x.w<y.w;}
int n,m,k,f[10005];
int main(){
    freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		e[i]={u,v,w};
	}
	sort(e+1,e+m+1,cmp);
	int ans=0,cnt=0;
	for(int i=1;i<=m;i++){
		if(cnt<n-1&&(!(f[e[i].u]&&f[e[i].v]))){
			ans+=e[i].w;
			f[e[i].u]=1,f[e[i].v]=1;
			cnt++;
		}
	}
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

