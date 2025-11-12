#include<bits/stdc++.h>
using namespace std;
struct node{
	long long u,v,w;
}e[5000001],e1[5000001];
long long fa[1000010],c[1000010],a[1010][1010],val[1010],n,m,k,mn=1e18;
int find(int x){
	if(x==fa[x]) return x;
	return fa[x]=find(fa[x]);
}
bool cmp(node a,node b){
	return a.w<b.w;
}
long long krusal(int num,int p){
	for(int i=1;i<=num;i++) fa[i]=i;
	long long ans=0,cnt=0;
	sort(e1+1,e1+p+1,cmp);
	for(int i=1;i<=p;i++){
		int eu=find(e1[i].u),ev=find(e1[i].v);
		if(eu==ev) continue;
		ans+=e1[i].w;
		if(ans>=mn) return 1e18;
		fa[ev]=eu;
		if(++cnt==num-1) break;
	}
	return ans;
}
void dfs(int step){
	if(step>n+k){
		int cnt=m,cnt1=0,sum=0;
		for(int i=1;i<=m;i++){
			e1[i].u=e[i].u;
			e1[i].v=e[i].v;
			e1[i].w=e[i].w;
		}
		for(int i=1+n;i<=k+n;i++){
			if(c[i]){
				for(int j=1;j<=n;j++){
					e1[++cnt].u=i;
					e1[cnt].v=j;
					e1[cnt].w=a[i][j];
				}
				cnt1++;
				sum+=val[i];
			}
		}
		if(sum<mn) mn=min(mn,sum+krusal(n+cnt1,cnt));
		return ;
	}
	dfs(step+1);
	c[step]=1;
	dfs(step+1);
	c[step]=0;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++) cin>>e[i].u>>e[i].v>>e[i].w;
	for(int i=n+1;i<=k+n;i++){
		cin>>val[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	dfs(1+n);
	cout<<mn;
	return 0;
}
