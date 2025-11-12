#include<bits/stdc++.h>
#define maxn 1010
using namespace std;
int a[maxn],dp[maxn][maxn],n,k,cnt,ans,lastans;
bool used[maxn][maxn][1];
pair<int,int> canuse[maxn];
void dfs(int l,int r){
	if(r==n) return ;
	bool flag=false;
	for(int i=1;i<=cnt;i++){
		if(dp[canuse[i].first][canuse[i].second]==k
		&&canuse[i].first>l&&canuse[i].second>r){
			ans++;
			lastans=max(lastans,ans);
			dfs(canuse[i].first,canuse[i].second);
			ans--;
		}
	}
	if(!flag) return ;
	return;
}
int main(){
	//别注释freopen！
	//多测要清空！
	//做完检查！
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++){
		dp[i][i]=a[i];
		canuse[++cnt].first=canuse[cnt].second=i;
	}
	for(int i=1;i<=n;i++){ 
		for(int j=i+1;j<=n;j++){
			dp[i][j]=dp[i][j-1]^a[j];
			canuse[++cnt].first=i,canuse[cnt].second=j;
		}
	}//but not dp
	/*for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			printf("%d,%d:%d\n",i,j,dp[i][j]);
		}
	}*/
	for(int i=1;i<=cnt;i++){
		if(dp[canuse[i].first][canuse[i].second]==k){
			if(!lastans) lastans=1;
			ans=1;
			dfs(canuse[i].first,canuse[i].second);
		}
	}
	printf("%d",lastans);
	return 0;
}
//一坨时间复杂度极高的代码 
//不管了屎山代码交给评测机 
