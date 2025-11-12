#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k,tot,fa[5000005],cost[15],a[15][20005],ans;
bool use[15];
struct node{
	int from,to,l;
}edge[5000005],temp[5000005];
bool cmp(node x,node y){
	return x.l<y.l;
}
int get(int x){
	if(fa[x]==x) return x;
	return fa[x]=get(fa[x]);
}
void dfs(int x){
	if(x>k){
		int cnt=0;
		tot=m;
		for(int i=1;i<=m;i++) temp[i]=edge[i];
		for(int i=1;i<=n;i++){
			if(use[i]){
				cnt+=cost[i];
				for(int j=1;j<=n-1;j++){
					for(int x=j+1;x<=n;x++){
						tot++;
						temp[tot].from=j;
						temp[tot].to=x;
						temp[tot].l=a[i][j]+a[i][x];
					}
				} 
			}
		}
		sort(temp+1,temp+1+tot,cmp);
		for(int i=1;i<=n;i++){
			fa[i]=i;
		}
		for(int i=1;i<=tot;i++){
			int t1=temp[i].from,t2=temp[i].to,t3=temp[i].l;
			if(get(t1)==get(t2)) continue;
			fa[get(t1)]=get(t2);
			cnt+=t3;
			if(cnt>ans) return;
		}
		
		ans=min(ans,cnt);
		return;
	}
	use[x]=1;
	dfs(x+1);
	use[x]=0;
	dfs(x+1);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>edge[i].from>>edge[i].to>>edge[i].l;
		temp[i]=edge[i];
	}
	tot=m;
	if(k==0){
		sort(edge+1,edge+1+tot,cmp);
		for(int i=1;i<=n;i++){
			fa[i]=i;
		}
		for(int i=1;i<=tot;i++){
			int t1=edge[i].from,t2=edge[i].to,t3=edge[i].l;
			if(get(t1)==get(t2)) continue;
			fa[get(t1)]=get(t2);
			ans+=t3;
		}
		cout<<ans;		
	}
	else{
		for(int i=1;i<=k;i++){
			cin>>cost[i];
			for(int j=1;j<=n;j++) cin>>a[i][j];
		}
		ans=0x3f3f3f3f;
		dfs(1);
		cout<<ans;
	}
	return 0;
}

