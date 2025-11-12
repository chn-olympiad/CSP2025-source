#include <bits/stdc++.h>
using namespace std;
struct eg{
	long long u,v,w;
}mapp[2000005];
long long n,m,k,c[100],a[100][10005],ans,fa[100005],cns=1;
int find(int x){
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}
bool cmp(eg a,eg b){
	return a.w<b.w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m>>k;
	long long mm=m;
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=m;i++)cin>>mapp[i].u>>mapp[i].v>>mapp[i].w;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			if(a[i][j]==0){
				for(int p=1;p<=n;p++){
					mapp[++mm].u=j;
					mapp[mm].v=p;
					mapp[mm].w=a[i][p];
				}
			}
		}
	}sort(mapp+1,mapp+mm+1,cmp);
	for(int i=1;i<=mm;i++){
		int eu=mapp[i].u,ev=mapp[i].v;
		eu=find(eu),ev=find(ev);
		if(eu==ev)continue;
		fa[eu]=ev;
		ans+=mapp[i].w;
		cns++;
		if(cns==n)break;
	}cout<<ans;
	return 0;
}
