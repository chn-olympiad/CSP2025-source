#include<bits/stdc++.h>
using namespace std;
struct node{
	long long u,v,w;
}se[2000005];
long long n,m,k,len,u,v,w,ans,fa[10005],idx,t,W[10005];
long long Find(long long x){
	if(fa[x]==x)return x;
	return fa[x]=Find(fa[x]);
}
bool cmp(node x,node y){
	return x.w<y.w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		len++;
		se[len].u=u;
		se[len].v=v;
		se[len].w=w;
	}
	for(int i=1;i<=k;i++){
		cin>>t;
		idx=0;
		for(int j=1;j<=n;j++){
			cin>>W[j];
			if(W[j]==0)idx=j;
		}
		for(int j=1;j<=n;j++){
			if(j==idx)continue;
			len++;
			se[len].u=idx;
			se[len].v=j;
			se[len].w=W[j];
		}
	}
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	sort(se+1,se+1+len,cmp);
	for(int i=1;i<=len;i++){
		u=se[i].u;
		v=se[i].v;
		w=se[i].w;
		u=Find(u),v=Find(v);
		if(u==v)continue;
		ans+=w;
		fa[u]=v;
	}
	cout<<ans;
	return 0;
} 
