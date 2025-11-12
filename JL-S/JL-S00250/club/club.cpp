#include <bits/stdc++.h>
using namespace std;
int t, n, ans = -1;
priority_queue<int> Q;
int a[114514][4];
int dis[45][45][45];
bool check(int A, int B, int C, int sum){
	//printf("dis[%d][%d][%d]=%d\n",A,B,C,dis[A][B][C]);
	
	if (dis[A][B][C] < sum)return 1;
	else return 0;
}
void dfs(int x, int A, int B, int C, int sum){
	//printf("%d %d %d:%d\n",A, B, C, dis[A][B][C]);
	if (x > n){
		ans = max(ans, sum);
		return;
    }
    if (A < n / 2 && check(A+1, B, C, sum + a[x][1]))
    {dis[A+1][B][C] = sum + a[x][1]; dfs(x+1, A+1, B, C, sum + a[x][1]);}
    if (B < n / 2 && check(A, B+1, C, sum + a[x][2]))
    {dis[A][B+1][C] = sum + a[x][2]; dfs(x+1, A, B+1, C, sum + a[x][2]);}
    if (C < n / 2 && check(A, B, C+1, sum + a[x][3]))
    {dis[A][B][C+1] = sum + a[x][3]; dfs(x+1, A, B, C+1, sum + a[x][3]);}
}
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%d",&t);
	while (t--){
		for (int i = 0; i <= 40; i++)
			for (int j = 0; j <= 40; j++)
				for (int k = 0; k <= 40; k++)
					dis[i][j][k] = -1;
		scanf("%d",&n);
		if (n <= 30){
			dis[0][0][0] = 0;
			for (int i = 1; i <= n; i++)
			{
				for (int j = 1; j <= 3; j++){
					scanf("%d",&a[i][j]);
				}
			}
			ans = -1;
			dfs(1, 0, 0, 0, 0);
			printf("%d\n", ans);
		} else {
			for (int i = 1; i <= n; i++){
				for (int j = 1; j <= 3; j++)
					scanf("%d",&a[i][j]);
				Q.push(a[i][1]);
			}
			int sum = 0;
			for (int i = 1; i <= n / 2; i++){
				sum += Q.top();
				Q.pop();
			}
			printf("%d\n",sum);
		}
	}
}
