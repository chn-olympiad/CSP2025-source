#include <bits/stdc++.h>
using namespace std;
struct data{
	int d[3];
	int fav, sec, lea;//最喜欢，第二， 最不
	int cost[3][3];
};
int tooD = 0;
vector<data> vec;
bool cmp(int a, int b) {
	int acost = 0x7fffffff, bcost = 0x7fffffff;
	for (int i = 0; i < 3; i++) {
		if (i != tooD) {
			if (acost > vec[a].cost[tooD][i])
				acost = vec[a].cost[tooD][i];
		}
	}
	for (int i = 0; i < 3; i++) {
		if (i != tooD) {
			if (bcost > vec[b].cost[tooD][i])
				bcost = vec[b].cost[tooD][i];
		}
	}
	return acost > bcost;
}// return a > b;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		vector<data> clean;
		vec = clean;
		vector<int> D[3] = {};
		for (int i = 0; i < n; i++) {
			data a;
			cin >> a.d[0] >> a.d[1] >> a.d[2];
			int max = 0;
			for (int i = 0; i < 3; i++) {
				if (max < a.d[i]) {//找最大 
					a.fav = i;//最喜欢 
					max = a.d[i];
				}
			}
			int max2 = 0;
			for (int i = 0; i < 3; i++) {
				if (i != a.fav) {//排除 
					if (max2 < a.d[i]) {
						a.sec = i;//第二喜欢 
						max2 = a.d[i];//第二大
					}
				}
			}
			for (int i = 0; i < 3; i++) {
				if (i != a.fav && i != a.sec)//两个都不是
				{
					a.lea = i;//最不
				}
			}
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					a.cost[i][j] = a.d[i] - a.d[j];//从i换为j的代价 
				}
			}
			D[a.fav].push_back(i);
			vec.push_back(a);
		}//输入
		if ((int)D[0].size()<=n/2&&(int)D[1].size()<=n/2&&(int)D[2].size()<=n/2) {
		}
		else {
			for (int i = 0; i < 3; i++) {
				if ((int)D[i].size()>n/2) {//找到超出的部门
					tooD = i;
					sort(D[i].begin(), D[i].end(), cmp);//按最小转移代价排序，小的在后 
					while((int)D[i].size()>n/2) {
						int f = D[i][D[i].size() - 1];//D的末尾
						if ((int)D[vec[f].sec].size() + 1 <= n/2) {
							D[vec[f].sec].push_back(f);
						}
						else {
							D[vec[f].lea].push_back(f);
						}
						D[i].pop_back();//清除末尾
					}
				}
			}
			
		}
		int ans = 0;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < (int)D[i].size(); j++) {
				ans += vec[D[i][j]].d[i];
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
