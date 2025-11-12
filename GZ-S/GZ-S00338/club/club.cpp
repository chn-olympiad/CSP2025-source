//GZ-S00338 毕节梁才学校 王艺杰
#include <bits/stdc++.h>
using namespace std;
map <pair<pair<pair<int,int>,int>,int>,int> mem;
int t;
int n,m=3;
int a[100010][5],num[5];
int dfs(int x){
	int ans=0;
	for (int i=1; i<=m; i++){
		if (num[i]<n/2&&x<=n){
			num[i]++;
			if (mem[{{{num[1],num[2]},num[3]},x+1}]==0){ 
				ans=max(dfs(x+1)+a[x][i],ans);
				mem[{{{num[1],num[2]},num[3]},x}]=ans;
			}else{
				ans=mem[{{{num[1],num[2]},num[3]},x}];
			}
			
			num[i]--;
		}
	}
	
	return ans;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.ans","w",stdout);
	cin  >> t;
	while (t--){
		memset(a,0,sizeof(a));
		memset(num,0,sizeof(num));
		mem.clear();
		scanf("%d",&n);
		for (int i=1; i<=n; i++){
			for (int j=1; j<=3; j++){
				scanf("%d",&a[i][j]);
			}
		}
		int ans=dfs(1);
		cout << ans<<endl;
	} 
	fclose(stdin);
	fclose(stdout);
	return 0;
}
