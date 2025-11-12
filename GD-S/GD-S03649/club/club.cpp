#include<bits/stdc++.h>
using namespace std;
int num[3][100010];
int sh[3],n;
int maxn;
void dfs(int js,int tj){
	if(js==n+1){
		maxn=max(maxn,tj);
	}
	for(int i=1;i<=3;i++){
		if(sh[i]<n/2){
			sh[i]++;
			dfs(js+1,tj+num[i-1][js]);
			sh[i]--;
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d",&t);
	for(int i=1;i<=t;i++){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d %d %d",&num[0][i],&num[1][i],&num[2][i]);
		}
		dfs(1,0);
		printf("%d\n",maxn);
		maxn=sh[0]=sh[1]=sh[2]=0;
	}
	return 0;
}
