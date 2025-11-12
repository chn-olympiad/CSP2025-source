#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,k,c[20],a[20][10004],cnt,res,ans=1e18,fa[20004],sn,mp[1003][1003],cpd;
struct node{
	ll u,v,val;
}e[2000006],s[2000006];
bool cmp(node x,node y){
	return x.val<y.val;
}
ll find(ll x){return x==fa[x]?x:fa[x]=find(fa[x]);
}
ll sp=0;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cpd=clock();
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++) cin>>e[i].u>>e[i].v>>e[i].val;
	for(int i=1;i<=k;i++) {
		cin>>c[i];
		sp+=(c[i]==0);
		for(int j=1;j<=n;j++) cin>>a[i][j];
	}
	if(sp==k){
		for(int j=1;j<n;j++) for(int o=j+1;o<=n;o++) mp[j][o]=mp[o][j]=1e9;
		for(int j=1;j<=n;j++) fa[j]=j;
		for(int j=1;j<=m;j++) mp[e[j].u][e[j].v]=e[j].val,mp[e[j].v][e[j].u]=e[j].val;
		res=0;
		cnt=0;
		for(int j=0;j<k;j++) {
			for(int f=1;f<n;f++) {
				for(int t=f+1;t<=n;t++){
					mp[f][t]=min(mp[f][t],a[j+1][f]+a[j+1][t]);
					mp[t][f]=min(mp[t][f],a[j+1][f]+a[j+1][t]);
				}
			}
		}
		for(int j=1;j<n;j++) for(int o=j+1;o<=n;o++) {
			s[++cnt].u=j;
			s[cnt].v=o;
			s[cnt].val=mp[j][o];
		}
		sort(s+1,s+1+cnt,cmp);
		for(int j=1;j<=cnt;j++) {
			if(find(s[j].u)!=find(s[j].v)){
				res+=s[j].val;
				fa[find(s[j].u)]=find(s[j].v);
			}
		}
		return cout<<res,0;
	}
	for(int i=0;i<(1<<k);i++){
		for(int j=1;j<n;j++) for(int o=j+1;o<=n;o++) mp[j][o]=mp[o][j]=1e9;
		for(int j=1;j<=n;j++) fa[j]=j;
		for(int j=1;j<=m;j++) mp[e[j].u][e[j].v]=e[j].val,mp[e[j].v][e[j].u]=e[j].val;
		res=0;
		cnt=0;
		for(int j=0;j<k;j++) if(i&(1<<j)){
			res+=c[j+1];
			for(int f=1;f<n;f++) {
				for(int t=f+1;t<=n;t++){
					mp[f][t]=min(mp[f][t],a[j+1][f]+a[j+1][t]);
					mp[t][f]=min(mp[t][f],a[j+1][f]+a[j+1][t]);
				}
			}
		}
		for(int j=1;j<n;j++) for(int o=j+1;o<=n;o++) {
			s[++cnt].u=j;
			s[cnt].v=o;
			s[cnt].val=mp[j][o];
		}
		sort(s+1,s+1+cnt,cmp);
		for(int j=1;j<=cnt;j++) {
			if(find(s[j].u)!=find(s[j].v)){
				res+=s[j].val;
				fa[find(s[j].u)]=find(s[j].v);
			}
		}
		ans=min(ans,res);
		if(clock()-cpd>=1000) return cout<<ans,0;
	}
	cout<<ans;
}
