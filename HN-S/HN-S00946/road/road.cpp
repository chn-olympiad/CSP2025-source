#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int s=10020;
struct node{
	int u,v;
	ll wei;
}len[1000010];
ll a,ans,aans;
int n,m,k,f[1000010],sum;
bool pd;
int find(int x){
	if(f[x]==x)return x;
	return f[x]=find(f[x]);
}


bool cmp(node a,node b){
	return a.wei<b.wei;
}
void tre(){
	sort(len+1,len+m+1,cmp);
	for(int i=1;i<=m;i++){
		int fu=find(len[i].u),fv=find(len[i].v);
		if(fu==fv)continue;
		ans+=len[i].wei;
		f[fu]=fv;
	}
	return ;
}
int main(){
	cin>>n>>m>>k;
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	for(int i=1;i<=n;i++)f[i]=i;
	for(int i=1;i<=m;i++){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		len[i].u=u;len[i].v=v;len[i].wei=w;
	}
	pd=1;
	for(int i=1;i<=k;i++){
		ll u,now;
		cin>>now;
		if(now)aans=max(aans,now);
		for(int j=1;j<=n;j++){
			cin>>now;
			if(now!=0)pd=0;
		}
	}
	tre();
	if(pd&&k!=0)cout<<aans;
	else cout<<ans;
	return 0;
}
/*
4 4 1
1 4 6
2 3 7
4 2 5
4 3 4
1 0 0 0 0
*/
