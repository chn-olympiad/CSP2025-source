#include<bits/stdc++.h>
using namespace std;
int T,n,a[100010][4],ans,cnt;
int used[4];
void dfs(int dep){
	if(dep>n) return;
	for(int i=1;i<=3;i++){
		if(used[i]+1<=n/2){
			used[i]++;
			cnt+=a[dep][i];
			ans=max(ans,cnt);
			dfs(dep+1);
			used[i]--;
			cnt-=a[dep][i];
		}
	}
} 
int main(){
	freopen("club3.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		memset(used,0,sizeof used);
		ans=0,cnt=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
		}
		dfs(1);
		printf("%d\n",ans);
	}
	return 0;
}
//T1怎么这么爱考贪心啊 
