#include<bits/stdc++.h>
using namespace std;

const int MAX_N = 1e5+5;

int n, t, stu[MAX_N][3], ans;

int main(){
	
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	scanf("%d", &t);
	for(int i = 0, md; i < t; i++){
		scanf("%d", &n);
		ans = 0;
		stack<int> club[3];
		priority_queue<int> pq;
		for(int j = 1; j <= n; j++){
			scanf("%d %d %d", &stu[j][0], &stu[j][1], &stu[j][2]);
			md = stu[j][0] >= max(stu[j][1], stu[j][2])?
				0 : (stu[j][1] >= stu[j][2]? 1 : 2);
			club[md].push(j);
			ans += stu[j][md];
		}
		if(club[0].size() <= n/2 && 
			club[1].size() <= n/2 && 
			club[0].size() <= n/2){
			printf("%d\n", ans);
			continue;
		}
		int sc, orz, cnt;
		if(club[0].size() > n/2) sc = 0;
		else if (club[1].size() > n/2) sc = 1;
		else sc = 2;
		cnt = club[sc].size();
		while(!club[sc].empty()){
			orz = max(stu[club[sc].top()][(sc+1)%3], 
				stu[club[sc].top()][(sc+2)%3]) - stu[club[sc].top()][sc];
			pq.push(orz);
			club[sc].pop();
		}
		while(cnt > n/2){
			ans += pq.top();
			pq.pop();
			cnt--;
		}
		printf("%d\n", ans);
	}
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
} 
