#include <bits/stdc++.h>
using namespace std;

int n, heart[5][100005], maxh = -1, people[5];

void dfs(int step, int myheart){
	if(step > n){
		maxh = max(maxh, myheart);
	}
	for(int i = 1;i <= 3;i++){
		if(people[i] + 1 <= n / 2){
			people[i]++;
			dfs(step + 1, myheart + heart[i][step]);
			people[i]--;
		}
	} 
}

int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T;
	scanf("%d", &T);
	while(T--){
		scanf("%d", &n);
		for(int i = 1;i <= n;i++)
			scanf("%d %d %d", &heart[1][i], &heart[2][i], &heart[3][i]);
		maxh = -1;
		dfs(1, 0);
		printf("%d\n", maxh);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
