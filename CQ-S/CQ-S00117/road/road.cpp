#include<bits/stdc++.h> 
using namespace std;
long long n,m,k,fa[1055],a[15][1055],b[15],vis[15],ans;
struct node{
	long long x,y,z;
}c[1000005],t[2000005];
int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
bool cmp(node x,node y){
	return x.z<y.z;
}
long long f(){
	long long sum=0,cnt=0;
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++){
		int xx=find(c[i].x),yy=find(c[i].y);
		if(xx!=yy){
			fa[xx]=yy;
			sum+=c[i].z;
			cnt++;
		}
		if(cnt==n){
			return sum;
		}
	}
	return sum;
} 
long long check(){
	long long sum=0,xb=m,xxb=n,cnt=0;
	for(int i=1;i<=m;i++) t[i]=c[i];
	for(int i=1;i<=k;i++){
		if(vis[i]==1){
			xxb++;
			for(int j=1;j<=n;j++){
				t[++xb]={xxb,j,a[i][j]};
			}
			sum+=b[i];
			if(sum>ans) return 1e17; 
		}
	}
	sort(t+1,t+xb+1,cmp);
	for(int i=1;i<=xxb;i++) fa[i]=i;
	for(int i=1;i<=xb;i++){
		int xx=find(t[i].x),yy=find(t[i].y);
		if(xx!=yy){
			fa[xx]=yy;
			sum+=t[i].z;
			cnt++;
			if(sum>ans) return 1e17; 
		}
		if(cnt==xxb) return sum;
	}
	return sum;
}
void dfs(int step,long long sum){
	if(sum>ans) return ;
	if(step==k+1){
		ans=min(ans,check());
		return ;
	}
	dfs(step+1,sum);
	vis[step]=1;
	dfs(step+1,sum+b[step]);
	vis[step]=0;
} 
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>c[i].x>>c[i].y>>c[i].z;
	}
	sort(c+1,c+m+1,cmp);
	for(int i=1;i<=k;i++){
		cin>>b[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	ans=f();
	if(k==0){
		cout<<ans;
		return 0;
	}
	dfs(1,0);
	cout<<ans;
	return 0;
}
