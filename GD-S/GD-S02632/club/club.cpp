#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int num[N][4],s[4];
int ans,n;
void dfs(int u,int sum){
	if(u>n){
		ans=max(ans,sum);
		return;
	}
	for(int i=1;i<=3;i++){
		if(s[i]==n/2) continue;
		s[i]++;
		dfs(u+1,sum+num[u][i]);
		s[i]--;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		ans=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d %d %d",&num[i][1],&num[i][2],&num[i][3]);
		}
		dfs(1,0);
		printf("%d\n",ans);
	}
	return 0;
}
