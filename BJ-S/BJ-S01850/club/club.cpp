//社团招新
/*
	linux操作可能有问题   解压文件可能有问题 
	
	
	学生应该熟悉一下相关操作
	* 
	解题思路： 贪心 ？DP？
	
	每个社团都不能 超过n/2 
		如果不限制每个社团人数  那么  每个人选最满意的社团就好  此时满意度的和最大
		限制了的话  让一部分人换 次满意的 社团
		* 哪部分人换？ 满意度排名后 超过n/2的人 不一定 
 
	三个队列 放每个人的 <满意度，位置> 即可
 
 
 
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
const int N = 1e5 + 10;
int t, n, a[N][5];
/*
struct stu{
	int feel, pos;
};*/
/*pair<int, int> stu; */  // 满意度 位置
int main(){
	
	freopen("club.in","r",stdin);
	freopen("club.out", "w", stdout);
	
	scanf("%d", &t);
	while(t--){
		int sum = 0;
		// 输入数据
		scanf("%d", &n);
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= 3; j++)
				scanf("%d", &a[i][j]);
		
		vector< pair<int, int> > v[4]; // 三组学生
		
		for(int i = 1; i <= n; i++){
			if(a[i][1] > a[i][2] && a[i][1] > a[i][3]) v[1].push_back({a[i][1], i}), sum+=a[i][1]; // 每个人先到最满意的
			else if(a[i][2] > a[i][1] && a[i][2] > a[i][3]) v[2].push_back({a[i][2], i}), sum+=a[i][2];
			else if(a[i][3] > a[i][1] && a[i][3] > a[i][2]) v[3].push_back({a[i][3], i}), sum+=a[i][3];
			else sum += max(max(a[i][1], a[i][2]),a[i][3]); // 有重复 默认分到人少的社团
			
		}
		
		// 排序
		sort(v[1].begin(), v[1].end());
		sort(v[2].begin(), v[2].end());
		sort(v[3].begin(), v[3].end());
		
		
		
		// 调整
		int flag = 0;
		if(int(v[1].size()) > n / 2) flag = 1;
		if(int(v[2].size())> n / 2) flag = 2;
		if(int(v[3].size()) > n / 2) flag = 3;
		
		// 扣掉多加的满意度 谁换社团代价小 换谁
		if(flag){
			vector<int> tmp; 
			
			for(int i = 0; i < int(v[flag].size());i++){
					int pos = v[flag][i].second;
					int d[] = {a[pos][1], a[pos][2], a[pos][3]};
					sort(d, d+3);
					tmp.push_back(d[2] - d[1]); // 存储换社团代价
			
			}
			
			sort(tmp.begin(), tmp.end());
			
			// 裁掉多余前k人
			int k = v[flag].size() - n/2;
			for(int i = 0; i < k; i++){
				sum -= tmp[i];
			}
		}
		cout << sum << endl;
	}
	
	return 0;
}
