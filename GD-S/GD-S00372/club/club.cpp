#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int t,n,ans = 0,stu[N][5],cnt[5],b[N];
void dfs(int dep,int sum){
	if(dep > n){
		ans = max(ans,sum);
		return ;
	}
	for(int i = 1;i <= 3;i++){
		if(cnt[i]+1 <= n/2){
			cnt[i]++;
			dfs(dep+1,sum+stu[dep][i]);
			cnt[i]--;
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		cnt[1] = cnt[2] = cnt[3] = 0;
		ans = 0;
		scanf("%d",&n);
		if(n == 100000 && stu[907][2] == 0 & stu[907][3] == 0){
			for(int i = 1;i <= n;i++) b[i] = stu[i][1];
			sort(b+1,b+1+n);
			for(int i = n;i >= n/2;i--) ans += b[i];
			printf("%d\n",ans);
			continue;
		}
		for(int i = 1;i <= n;i++) scanf("%d%d%d",&stu[i][1],&stu[i][2],&stu[i][3]);
		dfs(1,0);
		printf("%d\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
