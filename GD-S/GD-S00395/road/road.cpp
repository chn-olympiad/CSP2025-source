#include<bits/stdc++.h>
using namespace std;
struct node{
	long long v,w;
};
long long n,m,k,ans=1e15;
vector<node> a[100010];
long long t[20],g[20][100010],cnt;
bool q[20];
struct ggg{
	long long x,y,z;
}gt[2000010],kk[2000010];
int fa[100010];
int getfa(int x){
	if(fa[x]==x){
		return x;
	}
	return fa[x]=getfa(fa[x]);
} 
void lian(int x,int y){
	fa[getfa(x)]=getfa(y);
}
bool cmp(ggg x,ggg y){
	return x.z<=y.z;
}
long long mintree(){
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	for(int i=1;i<=cnt;i++){
		kk[i]=gt[i];
	}
	int cnt1=cnt;
	for(int i=1;i<=k;i++){
		if(q[i])for(int j=1;j<=n;j++)if(j!=i){
			cnt1++;
			kk[cnt1]=ggg{k,j,g[k][j]};
		}
	}
	sort(kk+1,kk+cnt1+1,cmp);
	//cout<<cnt1<<' '<<endl;
	int i=1,ans=0;
	cnt1=0;
	while(i<n){
		cnt1++;
		if(getfa(kk[cnt1].x)==getfa(kk[cnt1].y)){
			continue;
		}
		i++;
		//cout<<kk[cnt1].z<<' ';
		ans+=kk[cnt1].z;
		lian(kk[cnt1].x,kk[cnt1].y);
	}
	return ans;
}
/*4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4*/
void dfs(long long i,long long sum){
	if(i==k+1){
		ans=min(ans,sum+mintree());
		return ;
	}
	else{
		q[i]=1;
		dfs(i+1,sum+t[i]);
		q[i]=0;
		dfs(i+1,sum);
	}
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(long long i=1;i<=m;i++){                    
		long long u,v,w;
		cin>>u>>v>>w;
		cnt++;
		gt[cnt]={u,v,w};
	}
	for(long long i=1;i<=k;i++){
		cin>>t[i];
		for(long long j=1;j<=n;j++){
			cin>>g[i][j];
		}
	}
	dfs(0,0);
	cout<<ans;
} 
