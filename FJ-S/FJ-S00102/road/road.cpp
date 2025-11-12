#include<bits/stdc++.h>
using namespace std;
struct node{
	int st,to,val;
} edge[2000010];
int n,m,k,cnt,feiy[11],fa[10100];
long long ans=1e15;
bool fla[11];
bool cmp(node x,node y){
	return x.val<=y.val;
}
int find(int t){
	if(fa[t]==t)
		return t;
	return fa[t]=find(t);
}
long long kruskal(int mx,long long now){
	int wz=1,count=0;
	long long sum=now;
	while(count<=mx){
		if(edge[wz].st>n){
			if(fla[edge[wz].st-n]==0){
				wz++;
				continue;
			}
		}
		if(find(edge[wz].st)==find(edge[wz].to)){
			wz++;
			continue;
		}
		sum+=edge[wz].val;
		int xx=find(edge[wz].st),yy=find(edge[wz].to);
		fa[xx]=yy;
		count++;
		wz++;
	}
	return sum;
}
void dfs(int num,int cnt,long long now){
	if(num==k){
		long long kkk=kruskal(n+cnt-1,now);
		ans=min(ans,kkk);
		return;
	}
	for(int i=0;i<=1;i++){
		fla[num]=i;
		dfs(num+1,cnt+i,now+feiy[num]*i);
	}
	return;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n+k;i++)
		fa[i]=i;
	for(int i=1;i<=m;i++){
		int uu,vv,ww;
		cin>>uu>>vv>>ww;
		cnt++;
		edge[cnt].st=uu;
		edge[cnt].to=vv;
		edge[cnt].val=ww;
	}
	for(int i=1;i<=k;i++){
		cin>>feiy[i];
		for(int j=1;j<=n;j++){
			int c;
			cin>>c;
			cnt++;
			edge[cnt].st=n+i;
			edge[cnt].to=j;
			edge[cnt].val=c;
		}
	}
	sort(edge+1,edge+cnt+1,cmp);
	dfs(1,0,0);
	cout<<ans<<endl;
	return 0;
}