#include<bits/stdc++.h>
using namespace std;
const int N=210;
int n, T;
int a[N][4];
long long ans, u[N/2][N/2][N/2];
priority_queue<int>q[4];
void dfs(int l,int m,int r,long long s){
	if(l>n/2||m>n/2||r>n/2)return;
	if(u[l][m][r]>=s)return;
	u[l][m][r]=s;
	if(l+m+r==n){
		ans=max(ans,s);
		
		return;
	}
	int k=l+m+r+1;
	dfs(l+1,m,r,s+a[k][1]);
	dfs(l,m+1,r,s+a[k][2]);
	dfs(l,m,r+1,s+a[k][3]);

}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
		}
		memset(u,-1,sizeof(u));
		ans=0;
		dfs(0,0,0,0);
		printf("%lld\n",ans);	
	}
	
	
	
	
	return 0;
} 
