#include<bits/stdc++.h>
using namespace std;
const int M=1e5+10;
int n,ij[M][4],num[M];
long long ans;
void dfs(int i,long long sum,int num[M]){
	if(i>n){
		ans=max(ans,sum);
		return;
	}
	for(int j=1;j<=3;j++){
		if(num[j]<n/2){
			num[j]++;
			dfs(i+1,sum+ij[i][j],num);
			num[j]--;
		}
	}
} 
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--){
		memset(num,0,sizeof(num));
		memset(ij,0,sizeof(ij));
		ans=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&ij[i][1],&ij[i][2],&ij[i][3]);
		}
		dfs(1,0,num);
		printf("%lld\n",ans);
	}
	return 0;
}

