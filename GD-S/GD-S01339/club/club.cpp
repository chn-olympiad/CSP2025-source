#include <bits/stdc++.h>
using namespace std;
int t, n, a[100005][3], num[3];
long long ans;
vector<int> v[3];
bool cmp0(int x, int y){
	return a[x][0] - max(a[x][1], a[x][2]) > a[y][0] - max(a[y][1], a[y][2]);
}
bool cmp1(int x, int y){
	return a[x][1] - max(a[x][0], a[x][2]) > a[y][1] - max(a[y][0], a[y][2]);
}
bool cmp2(int x, int y){
	return a[x][2] - max(a[x][1], a[x][0]) > a[y][2] - max(a[y][1], a[y][0]);
}
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		ans = 0;
		v[0].clear(), v[1].clear(), v[2].clear();
		num[0] = num[1] = num[2] = 0;
		for(int i = 1; i <= n; i++){
			scanf("%d%d%d", &a[i][0], &a[i][1], &a[i][2]);
			if(a[i][0] >= a[i][1] && a[i][0] >= a[i][2]){
				v[0].push_back(i);
			}else if(a[i][1] >= a[i][0] && a[i][1] >= a[i][2]){
				v[1].push_back(i);
			}else{
				v[2].push_back(i);
			}
		}
		if(v[0].size() > n / 2){
			for(auto i : v[1])ans += a[i][1];
			for(auto i : v[2])ans += a[i][2];
			sort(v[0].begin(), v[0].end(), cmp0);
			int i = 0;
			for(i = 0; i < n / 2; i++)ans += a[v[0][i]][0];
			for(; i < v[0].size(); i++)ans += max(a[v[0][i]][1], a[v[0][i]][2]);
		}else if(v[1].size() > n / 2){
			for(auto i : v[0])ans += a[i][0];
			for(auto i : v[2])ans += a[i][2];
			sort(v[1].begin(), v[1].end(), cmp1);
			int i = 0;
			for(i = 0; i < n / 2; i++)ans += a[v[1][i]][1];
			for(; i < v[1].size(); i++)ans += max(a[v[1][i]][0], a[v[1][i]][2]);
		}else if(v[2].size() > n / 2){
			for(auto i : v[0])ans += a[i][0];
			for(auto i : v[1])ans += a[i][1];
			sort(v[2].begin(), v[2].end(), cmp2);
			int i = 0;
			for(i = 0; i < n / 2; i++)ans += a[v[2][i]][2];
			for(; i < v[2].size(); i++)ans += max(a[v[2][i]][0], a[v[2][i]][1]);
		}else{
			for(auto i : v[1])ans += a[i][1];
			for(auto i : v[2])ans += a[i][2];
			for(auto i : v[0])ans += a[i][0];
		}
		printf("%lld\n", ans);
	}
	return 0;
} 
