#include <bits/stdc++.h>
#define ll long long
using namespace std;
struct edge{
	int u,v,w,cao;
}a[1500010];
bool cmp(edge x,edge y){
	return x.w<y.w;
}
int t[20],pa[11010],ans=0;
bool vis[20];
int find(int x){
	if(x==pa[x]) return x;
	return pa[x]=find(pa[x]);
}
void build(int x,int y){
	pa[find(x)]=pa[y];
}
int main(){
	ll n,m,k;
	ll cnt=0,cct=0;
	cin>>n>>m>>k;
	cnt=m;
	for(ll i=1;i<=m;i++){
		cin>>a[i].u>>a[i].v>>a[i].w;
		a[i].cao=0;
	}
	for(ll i=1;i<=k;i++){
		cin>>t[i];
		for(ll j=1;j<=n;j++){
			cin>>a[++cnt].w;
			a[cnt].u=i+n;
			a[cnt].v=j;
			a[cnt].cao=k;
		}
	}
	sort(a+1,a+cnt+1,cmp);
	for(int i=1;i<=n+k;i++){
		pa[i]=i;
	}
	for(ll i=1;i<=cnt;i++){
		if(find(a[i].u)==find(a[i].v)){
			continue;
		}
		else if(cct==n-1){
			break;
		}
		else{
			cct++;
			ans+=a[i].w;
			if(a[i].cao&&!vis[a[i].cao]){
				ans+=t[a[i].cao];
			}
			build(a[i].u,a[i].v);
		}
	}
	cout<<ans<<endl;
	return 0;
}
