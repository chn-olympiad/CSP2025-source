#include<bits/stdc++.h>
using namespace std;
int t, n, ans, f[105][105][105];
struct node{
	int x, y, z;
}a[100005];
void dfs(int k, int d, int u, int v, int w){
	if(u+u>n || v+v>n || w+w>n || d<=f[u][v][w]) return ;
	f[u][v][w]=d;
	if(k>n){
		if(d>ans) ans=d;
	}else{
		dfs(k+1,d+a[k].x,u+1,v,w);
		dfs(k+1,d+a[k].y,u,v+1,w);
		dfs(k+1,d+a[k].z,u,v,w+1);
	}
}
bool cmp1(node xx, node yy){
	return xx.x>yy.x;
}
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin>>t;
	while(t--){
		ans=0;
		int nn=0,mm=0;
		scanf("%d", &n);
		for(int i=1; i<=n; i++){
			scanf("%d%d%d", &a[i].x, &a[i].y, &a[i].z);
			nn+=a[i].y;
			mm+=a[i].z;
		}
		if(nn==0 && mm==0){
			sort(a+1, a+1+n, cmp1);
			for(int i=1; i+i<=n; i++){
				ans+=a[i].x;
			}
			cout<<ans<<"\n";
			continue;
		}
		memset(f,-1,sizeof(f));
		dfs(1, 0, 0, 0, 0);
		cout<<ans<<"\n";
	}
	return 0;
}

