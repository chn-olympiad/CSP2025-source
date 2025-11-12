#include<bits/stdc++.h>
using namespace std;
int t,ans,n;
int a[100005][3];
int l[3];
void dfs(int d,int s,int k){
	if(d>n){
		ans=max(ans,s);
		return;
	}
	if(l[k]>=n/2) return;
	l[k]++;
	for(int i=0;i<3;i++) dfs(d+1,s+a[d][k],i);
	l[k]--;
	return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		ans=-1;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);
		}
		dfs(1,0,0);
		dfs(1,0,1);
		dfs(1,0,2);
		printf("%d\n",ans);
	}
	return 0;
}

