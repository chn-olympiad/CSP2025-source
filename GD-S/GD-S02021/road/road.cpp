#include <bits/stdc++.h>
using namespace std;
struct node{
	int u,v,w;
};
int n,m,k,fa[10005],fu,fv,cnt,x,cnt2;
int ansk[15],f[15],xx[15];
long long ans,anss;
node e[1000005],ek[15][10005];
vector<node>q,qq;
vector<int>wri;
bool cmp(node x,node y){
	return x.w<y.w;
}
int ff(int x){
	if(fa[x]==x)return x;
	return fa[x]=ff(fa[x]);
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)fa[i]=i;
    for(int i=1;i<=m;i++)cin>>e[i].u>>e[i].v>>e[i].w;
	sort(e+1,e+m+1,cmp);
	for(int i=1;i<=m;i++){
		fu=ff(e[i].u),fv=ff(e[i].v);
		if(fu==fv)continue;
		fa[fv]=fu;
		ans+=e[i].w;
		q.push_back(e[i]);
		if(++cnt==n-1)break;
	}
	for(int i=1;i<=k;i++){
		anss=0;
		cin>>xx[i];
		anss+=xx[i];
		qq.clear();
		for(int j=1;j<=n;j++){
			cin>>ek[i][j].w;
			ek[i][j].u=n+i;
			ek[i][j].v=j;
			qq.push_back({n+i,j,ek[i][j].w});
		}
	for(int j=0;j<q.size();j++)qq.push_back(q[j]);
	sort(qq.begin(),qq.end(),cmp);
	for(int j=1;j<=n+i;j++)fa[j]=j;
	cnt=0;
	for(int j=0;j<qq.size();j++){
		fu=ff(qq[j].u),fv=ff(qq[j].v);
		if(fu==fv)continue;
		fa[fv]=fu;
		anss+=qq[j].w;
		if(++cnt==n)break;
	}
	if(anss<ans){
		ans==anss;
		ansk[++cnt2]=i;
	}
}
    int cnt3;
    for(int i=1;i<=(1<<cnt2)-1;i++){
    	anss=0;
    	cnt3=0;
    	for(int j=1;j<=cnt2;j++)f[j]=0;
    	qq.clear();
    	int num=i;
    	while(num>0){
    		cnt3++;
    		if(num&1)f[cnt3]=1;
    		num/=2;
		}
		for(int j=n+1;j<=n+k;j++)fa[j]=j;
		for(int j=0;j<q.size();j++)qq.push_back(q[j]);
		for(int j=1;j<=cnt3;j++){
			if(f[j]){
				for(int ii=1;ii<=n;ii++){
					qq.push_back(ek[ansk[j]][ii]);
				}
				anss+=xx[ansk[j]];
			}
		}
		sort(qq.begin(),qq.end(),cmp);
	for(int j=1;j<=n;j++)fa[j]=j;
	cnt=0;
	for(int j=0;j<qq.size();j++){
		fu=ff(qq[j].u),fv=ff(qq[j].v);
		if(fu==fv)continue;
		fa[fv]=fu;
		anss+=qq[j].w;
		if(++cnt==n+cnt3-1)break;
	}
		if(anss<ans)ans=anss;
	}
	cout<<ans;
	return 0;
}
