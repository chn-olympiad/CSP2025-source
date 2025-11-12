#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k;
int fa[100020],c[20],cnt[100005],num;
struct node{
	int u,v,w;
}e[10000005];
bool cmp(node o,node p){
	return o.w<p.w;
}
int find(int x){
	return (fa[x]==x?x:fa[x]=find(fa[x]));
}
void merge(int u,int v){
	if(find(u)!=find(v)){
		fa[find(u)]=find(v);
	}
	return;
}
map<int,int> mp,mp2;
int solve(){
	sort(e+1,e+1+m,cmp);
	int ans=0;
	for(int i=1;i<=m;i++){
		if(mp2.size()==n)break;
		int u=e[i].u,v=e[i].v,w=e[i].w;
		if(find(u)!=find(v)){
			if(u>n){
				int hh=u-n;
				if(mp[hh]==0){
					ans+=c[hh];
					mp[hh]=1;
				}
			}else{
				mp2[u]++;
			}
			if(v>n){
				int hh=v-n;
				if(mp[hh]==0){
					ans+=c[hh];
					mp[hh]=1;
				}
			}else{
				mp2[v]++;
			}
			merge(u,v);
			ans+=w;
		}
	}
	return ans;
}
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n+k;i++){
		fa[i]=i;
	}
	for(int i=1;i<=m;i++){
		cin>>e[i].u>>e[i].v>>e[i].w;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>cnt[j];
			e[++m].u=i+n;
			e[m].v=j;
			e[m].w=cnt[j];
		}
//		for(int j=1;j<=n;j++){
//			for(int l=j+1;l<=n;l++){
//				num++;
//				e[m+num].u=j;
//				e[m+num].v=l;
//				e[m+num].w=cnt[j]+cnt[l];
//			}
//		}
	}
	cout<<solve()<<endl;
	return 0;
}