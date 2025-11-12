#include<bits/stdc++.h>
using namespace std;
int n,m,k,c[11],d[11][10001],f1;
bool f[10001];
long long sum=9999999999999,num;
struct node{
	int x,y;
};
vector<node> a[10001];
void dfs(int h){
	if(f1==n){
		sum=min(sum,num);
		return;
	}
	for(int i=0;i<a[h].size();i++){
		if(f[a[h][i].x]==1)continue;
		f[a[h][i].x]=1;
		num+=a[h][i].y;
		f1++;
		dfs(a[h][i].x);
		f[a[h][i].x]=0;
		num-=a[h][i].y;
		f1--;
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		a[x].push_back({y,z});
		a[y].push_back({x,z});
	}
	for(int i=1;i<=k;i++){
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++){
			scanf("%d",&d[i][j]);
		}
	}
	for(int i=1;i<=n;i++){
		fill(f+1,f+1+10000,false);
		f[i]=1;f1=1;
		dfs(i);
	}
	cout<<sum;
	return 0;
}
