#include <stdio.h>
#include <vector>
#include <algorithm>
int n, a[114514][3], _;
long long mx = 0;

void dfs(long long a_value, long long b_value, long long c_value, int a_cnt, int b_cnt, int c_cnt, int id) {
	if(a_cnt > n / 2 || b_cnt > n / 2 || c_cnt > n / 2) return ;
	if(id == n + 1) {
		if(mx < a_value + b_value + c_value) mx = a_value + b_value + c_value;
		return ;
	}
	if(a[id][0] >= a[id][1] && a[id][0] >= a[id][2]) {
		dfs(a_value + a[id][0], b_value, c_value, a_cnt + 1, b_cnt, c_cnt, id + 1);
		if(a[id][1] > a[id][2]) dfs(a_value, b_value + a[id][1], c_value, a_cnt, b_cnt + 1, c_cnt, id + 1);
		else dfs(a_value, b_value, c_value + a[id][2], a_cnt, b_cnt, c_cnt + 1, id + 1);
	}
	if(a[id][1] >= a[id][0] && a[id][1] >= a[id][2]) {
		dfs(a_value, b_value + a[id][1], c_value, a_cnt, b_cnt + 1, c_cnt, id + 1);
		if(a[id][0] > a[id][2]) dfs(a_value + a[id][0], b_value, c_value, a_cnt + 1, b_cnt, c_cnt, id + 1);
		else dfs(a_value, b_value, c_value + a[id][2], a_cnt, b_cnt, c_cnt + 1, id + 1);
	}
	if(a[id][2] >= a[id][0] && a[id][2] >= a[id][1]) {
		dfs(a_value, b_value, c_value + a[id][2], a_cnt, b_cnt, c_cnt + 1, id + 1);
		if(a[id][0] > a[id][1]) dfs(a_value + a[id][0], b_value, c_value, a_cnt + 1, b_cnt, c_cnt, id + 1);
		else dfs(a_value, b_value + a[id][1], c_value, a_cnt, b_cnt + 1, c_cnt, id + 1);
	}
	return ;
}
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	scanf("%d", &_);
	while(_--) {
		mx = 0;
		scanf("%d", &n);
		int i;
		std::vector<int> use_people[3];
		long long cnt = 0;
		for(i = 1; i <= n; i += 1) {
			scanf("%d %d %d", &a[i][0], &a[i][1], &a[i][2]);
			if(a[i][0] >= a[i][1] && a[i][0] >= a[i][2]) use_people[0].push_back(i), cnt += a[i][0];
			else if(a[i][1] >= a[i][0] && a[i][1] >= a[i][2]) use_people[1].push_back(i), cnt += a[i][1];
			else if(a[i][2] >= a[i][0] && a[i][2] >= a[i][1]) use_people[2].push_back(i), cnt += a[i][2];
		}
		if(n <= 15) {
			dfs(0, 0, 0, 0, 0, 0, 1);
			printf("%lld", mx);
			continue;
		}
		int finished = 0;
		while(finished == 0) {
			finished = 1;
			if(use_people[0].size() > n / 2) {
				std::sort(use_people[0].begin(), use_people[0].end(), [&](int x, int y) -> bool {
					return a[x][0]> a[y][0];
				});
				for(i = use_people[0].size() - 1; i >= n / 2; i -= 1) {
					cnt -= a[use_people[0][i]][0];
					if(a[use_people[0][i]][1] == a[use_people[0][i]][2]) {
						if(use_people[1].size() < use_people[2].size()) {
							cnt += a[use_people[0][i]][1];
							use_people[1].push_back(use_people[0][i]);
						}
						else {
							cnt += a[use_people[0][i]][2];
							use_people[2].push_back(use_people[0][i]);
						}
					}
					else if(a[use_people[0][i]][1] > a[use_people[0][i]][2]) {
						cnt += a[use_people[0][i]][1];
						use_people[1].push_back(use_people[0][i]);
					}
					else {
						cnt += a[use_people[0][i]][2];
						use_people[2].push_back(use_people[0][i]);
					}
					use_people[0].pop_back();
				}
				finished = 0;
			}
			if(use_people[1].size() > n / 2) {
				std::sort(use_people[1].begin(), use_people[1].end(), [&](int x, int y) -> bool {
					return a[x][1] > a[y][1];
				});
				for(i = use_people[1].size() - 1; i >= n / 2; i -= 1) {
					cnt -= a[use_people[1][i]][1];
					if(a[use_people[1][i]][0] == a[use_people[1][i]][2]) {
						if(use_people[0].size() < use_people[0].size()) {
							cnt += a[use_people[1][i]][0];
							use_people[0].push_back(use_people[1][i]);
						}
						else {
							cnt += a[use_people[1][i]][2];
							use_people[2].push_back(use_people[1][i]);
						}
					}
					else if(a[use_people[1][i]][0] > a[use_people[1][i]][2]) {
						cnt += a[use_people[1][i]][0];
						use_people[0].push_back(use_people[1][i]);
					}
					else {
						cnt += a[use_people[1][i]][2];
						use_people[2].push_back(use_people[1][i]);
					}
					use_people[1].pop_back();
				}
				finished = 0;
			}
			if(use_people[2].size() > n / 2) {
				std::sort(use_people[2].begin(), use_people[2].end(), [&](int x, int y) -> bool {
					return a[x][2] > a[y][2];
				});
				for(i = use_people[2].size() - 1; i >= n / 2; i -= 1) {
					cnt -= a[use_people[2][i]][2];
					if(a[use_people[2][i]][0] == a[use_people[2][i]][1]) {
						if(use_people[0].size() < use_people[1].size()) {
							cnt += a[use_people[2][i]][0];
							use_people[0].push_back(use_people[2][i]);
						}
						else {
							cnt += a[use_people[2][i]][1];
							use_people[1].push_back(use_people[2][i]);
						}
					}
					else if(a[use_people[2][i]][0] > a[use_people[2][i]][1]) {
						cnt += a[use_people[2][i]][0];
						use_people[0].push_back(use_people[2][i]);
					}
					else {
						cnt += a[use_people[2][i]][1];
						use_people[1].push_back(use_people[2][i]);
					}
					use_people[2].pop_back();
				}
				finished = 0;
			}
			
			/*printf("---------------A-------------\n");
			for(i = 0; i < use_people[0].size(); i += 1) {
				printf("%d %d %d\n", a[use_people[0][i]][0], a[use_people[0][i]][1], a[use_people[0][i]][2]);
			}
			printf("---------------A-------------\n");
			printf("---------------B-------------\n");
			for(i = 0; i < use_people[1].size(); i += 1) {
				printf("%d %d %d\n", a[use_people[1][i]][0], a[use_people[1][i]][1], a[use_people[1][i]][2]);
			}
			printf("---------------B-------------\n");
			printf("---------------C-------------\n");
			for(i = 0; i < use_people[2].size(); i += 1) {
				printf("%d %d %d\n", a[use_people[2][i]][0], a[use_people[2][i]][1], a[use_people[2][i]][2]);
			}
			printf("---------------C-------------\n\n");*/
		}
		printf("%lld\n", cnt);
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
