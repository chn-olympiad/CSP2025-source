#include<bits/stdc++.h>
using namespace std;
int n,m,k,tot;
struct node{
	int u,v;
	long long w;
}b[1000005];
struct node2{
	int u,v;
	long long w;
	int op;
};
struct dian{
	int to;
	long long val;
}a[15][10005];
bool cmp2(dian x,dian y){
	return x.val<y.val;
}
bool cmp(node x,node y){
	return x.w<y.w;
}
bool operator < (node2 x,node2 y){
	return x.w>y.w;
}
int fa[10005],vis[15],wz[15][10005];
int zhao(int x){
	if(x==fa[x]) return x;
	return fa[x]=zhao(fa[x]);
}
long long ans;
priority_queue<node2> q;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;++i){
		cin>>b[i].u>>b[i].v>>b[i].w;
		q.push((node2){b[i].u,b[i].v,b[i].w,0});
	}
	for(int i=1;i<=k;++i){
		for(int j=0;j<=n;++j){
			cin>>a[i][j].val;
			a[i][j].to=j;
		}
		sort(a[i]+1,a[i]+n+1,cmp2);
		wz[i][1]=2;
		q.push((node2){1,2,a[i][0].val+a[i][1].val+a[i][2].val,i});
	}
	//cout<<"T2:\n";
	ans=0;
	tot=n-1;
	for(int i=1;i<=n;++i) fa[i]=i;
	while(tot){
		node2 p=q.top();q.pop();
		int x,y;
		if(!p.op) x=zhao(p.u),y=zhao(p.v);
		else x=zhao(a[p.op][p.u].to),y=zhao(a[p.op][wz[p.op][p.u]].to);
		if(x!=y){
			fa[x]=y;
			ans+=p.w;
	//		if(!p.op) cout<<tot<<" "<<p.u<<" "<<p.v<<" "<<p.w<<" "<<p.op<<"\n";
	//		else cout<<tot<<" "<<a[p.op][wz[p.op][p.u]].to<<" "<<a[p.op][wz[p.op][p.v]].to<<" "<<p.w<<" "<<p.op<<"\n";
			tot--;
			if(p.op){
				if(!vis[p.op]){
					vis[p.op]=1;
					for(int j=2;j<=n;++j){
						wz[p.op][j]=1;
						q.push((node2){j,wz[p.op][j],a[p.op][j].val+a[p.op][wz[p.op][j]].val,p.op});
					}
				}
				wz[p.op][p.u]++;
				if(wz[p.op][p.u]==p.u) wz[p.op][p.u]++;
				q.push((node2){p.u,wz[p.op][p.u],a[p.op][p.u].val+a[p.op][wz[p.op][p.u]].val,p.op});
			}
		}
	}
	cout<<ans<<"\n";
	return 0;
}