#include<bits/stdc++.h>
using namespace std;
#define N 10004
#define M 1000006
int n,m,k;
struct node{
	int to,fr,val;
}edge[M+N*10];
node edge2[M+N*10];
int c[15],minN[N],vis[N],r[15][N],fa[N+10];
long long fin_ans=1000000009;
bool cmp(node a,node b){
	return a.val<b.val;
}
int find_fa(int a){
	if(fa[a]==a){
		return a;
	}
	return fa[a]=find_fa(fa[a]);
}
long long deal(){
	long long ans=0;
	int tot=n,h=0,cnt=0;
	for(int i=1;i<=m;i++){
		edge2[++h].fr=edge[i].fr;
		edge2[h].to=edge[i].to;
		edge2[h].val=edge[i].val;
	}
	for(int i=1;i<=k;i++){
		if(vis[i]){
			fa[i+n]=i+n;
			//ans+=c[i];
			for(int j=1;j<=n;j++){
				edge2[++h].fr=n+i;
				edge2[h].to=j;
				edge2[h].val=r[i][j];
			}
			tot++;
		}
	}
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	sort(edge2+1,edge2+h+1,cmp);
	int fx,fy;
	for(int i=1;i<=h;i++){
		fx=find_fa(edge2[i].to),fy=find_fa(edge2[i].fr);
		if(fx!=fy){
			fa[fx]=fy;
			ans+=edge2[i].val;
			cnt++;
			if(cnt==tot){
				return ans;
			}
		}
	}
	return ans;
}
void dfs(int st){
	if(st==k+1){
		fin_ans=min(fin_ans,deal());
		return ;
	}
	vis[st]=1;
	dfs(st+1);
	vis[st]=0;
	dfs(st+1);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&edge[i].fr,&edge[i].to,&edge[i].val);
	}
	if(k){
		int sum=0;
		for(int i=1;i<=k;i++){
			scanf("%d",&c[i]);
			sum+=c[i];
			minN[i]=1;
			for(int j=1;j<=n;j++){
				scanf("%d",&r[i][j]);
				if(r[i][j]<r[i][minN[i]]){
					minN[i]=j;
				}
			}
			r[i][minN[i]]+=c[i];
		}
		if(sum==0){
			//int flag;
			for(int i=1;i<=k;i++){
				for(int j=1;j<=n;j++){
					if(j!=minN[i]){
						edge[++m].to=j;
						edge[m].fr=minN[i];
						edge[m].val=r[i][j];
					}
				}
			}
			sort(edge+1,edge+m+1,cmp);
			int tot=0,f1,f2;
			fin_ans=0;
			for(int i=1;i<=n;i++){
				fa[i]=i;
			}
			for(int i=1;i<=m;i++){
				f1=find_fa(edge[i].to),f2=find_fa(edge[i].fr);
				if(f1!=f2){
					fin_ans+=edge[i].val;
					fa[f1]=f2;
					tot++;
					if(tot==n){
						break;
					}
				}
			}
			printf("%lld",fin_ans);
		}
		else{
			dfs(1);
			printf("%lld",fin_ans);
		}
	}
	else{
		sort(edge+1,edge+m+1,cmp);
		int tot=0,f1,f2;
		fin_ans=0;
		for(int i=1;i<=n;i++){
			fa[i]=i;
		}
		for(int i=1;i<=m;i++){
			f1=find_fa(edge[i].to),f2=find_fa(edge[i].fr);
			if(f1!=f2){
				fin_ans+=edge[i].val;
				fa[f1]=f2;
				tot++;
				if(tot==n){
					break;
				}
			}
		}
		printf("%lld",fin_ans);
	}
	
	return 0;
}
