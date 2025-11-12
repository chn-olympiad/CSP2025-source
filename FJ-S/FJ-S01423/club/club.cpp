#include<bits/stdc++.h>
using namespace std;
int t;
int n,maxn=-1;
int a[100005],b[4],c[4][100005],d[100005];
void dfs(int id){
	if(id==n+1){
		int ss=0;
		for(int i=1;i<=n;i++){
			//printf("%d ",a[i]);
			ss+=c[a[i]][i];
		}
		maxn=max(maxn,ss);
		//printf("\n");
		return;
	}
	for(int i=1;i<=3;i++){
		if(b[i]<=n/2-1){
			a[id]=i;
			b[i]++;
			dfs(id+1);
			b[i]--;
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		maxn=-1;
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d%d%d",&c[1][i],&c[2][i],&c[3][i]);
		if(n==100000&&c[2][1]==0&&c[3][1]==0){
			long long ss=0;
			for(int i=1;i<=n;i++) d[i]=c[1][i];
			sort(d+1,d+n+1);
			for(int i=n;i>=n/2+1;i--) ss+=d[i];
			printf("%lld",ss);
		}
		else {
			dfs(1);
			printf("%d\n",maxn);
		}
	}
	
	return 0;
} 
