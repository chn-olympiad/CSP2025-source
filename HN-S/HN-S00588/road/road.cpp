#include<bits/stdc++.h>
using namespace std;
struct road{
	int start;
	int end;
	int val;
	int from;
}r[2000010];
bool cmp(road a,road b){
	return a.val<b.val;
}
int father[10030];
int find(int x){
	while(x!=father[x]) x=father[x];
	return x;
}
bool connect(int x,int y){
	int i=find(x),j=find(y);
	if(i!=j){
		father[i]=j;
		return true;
	}
	return false;
}
bool use[11];
int c[11];
long long n;
long long dfs(int step,int k){
	long long ret=0;
	if(step==k+1){
		int cnt=0;
		for(int i=1;i<=k;i++)
			if(use[i]) cnt++,ret+=c[i];
		for(int i=0,j=0;i<n+cnt-1;j++){
			if(use[r[j].from] && connect(r[j].start,r[j].end))
				ret+=r[j].val,i++;
		}
		for(int i=1;i<=n+k;i++)
			father[i]=i;
		return ret;
	}else{
		use[step]=true;
		ret=dfs(step+1,k);
		use[step]=false;
		long long ret2;
		ret2=dfs(step+1,k);
		ret=min(ret,ret2);
	}
	return ret;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	long long m,k,ans,tot;
	cin>>n>>m>>k;
	tot=m;
	for(int i=1;i<=n+k;i++)
		father[i]=i;
	for(int i=1;i<=m;i++){
		scanf("%d",&r[i].start);
		scanf("%d",&r[i].end);
		scanf("%d",&r[i].val);
		r[i].from=0;
	}
	for(int i=1;i<=k;i++){
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++){
			scanf("%d",&r[tot].val);
			r[tot].start=n+i,r[tot].end=j;
			r[tot].from=i;
			tot++;
		}
	}
	use[0]=true;
	sort(r,r+tot,cmp);
	ans=dfs(1,k);
	printf("%lld",ans);
	return 0;
}
