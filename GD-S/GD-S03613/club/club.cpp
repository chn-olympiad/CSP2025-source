/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1

4
0 1 0
0 1 0
0 2 0
0 2 0

2
10 9 8
4 0 0
*/
#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;
int t,h,n,a[MAXN][4];
int c[4] = {0,0,0,0};

int dfs(int i,int j){
	int ai = 0,b = 0,ci = 0;
	
	if(i == n){
		return a[i][j];
	}

	if(c[1] < h){
		c[1]++;
		ai = a[i][j] + dfs(i + 1,1);
		c[1]--;
	} 
	
	if(c[2] < h){
		c[2]++;
		b = a[i][j] + dfs(i + 1,2);
		c[2]--;
	}
	
	if(c[3] < h){
		c[3]++;
		ci = a[i][j] + dfs(i + 1,3);
		c[3]--;
	}
	
	
	return max(max(ai,b),ci);
}

void solve(){

	scanf("%d",&n);
	h = n / 2;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= 3;j++){
			scanf("%d",&a[i][j]);
		}
	}
	
	
	int ai = 0,b = 0,ci = 0;
	c[1]++;
	ai = dfs(1,1);
	c[1]--;
	
	c[2]++;
	b = dfs(1,2);
	c[2]--;
	
	c[3]++;
	ci = dfs(1,3);
	c[3]--;
	int ans = max(max(ai,b),ci);
	printf("%d\n",ans);
	
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	scanf("%d",&t);
	while(t--){
		solve();
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
