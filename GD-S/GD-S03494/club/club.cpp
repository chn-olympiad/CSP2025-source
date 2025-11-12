#include<bits/stdc++.h>
using namespace std;

struct people {
	long long a;
	long long b;
	long long c;
};

const int maxn = 1e5 + 5;
long long t;
long long n;
people stu[maxn];//招新的人 
long long each_stu_num[5];//各社团人数 
long long max_sum = 0;//理想最大值，达到直接判定 
bool haved[maxn];//表示该学生是否已经参加社团 
bool flag = false;//辅助理想最大值进行特判 
long long _max_sum;//记录当前的最大值 

void dfs(long long last_stu, long long current_num, long long current_sum, long long total) {
	if (current_num >= total) {//到达边界 
		if (current_sum==max_sum) {
			flag=true;
			_max_sum=current_sum;
			return;
		}
		_max_sum=max(_max_sum, current_sum);
		return;
	}
	for (int i = last_stu + 1; i <= n; i++) {
		if (flag)
			return;  
		if (!haved[i]) {
			for (int j=1;j<=3;j++) {
				if (each_stu_num[j] + 1 <= n / 2) {
					haved[i]=true;
					each_stu_num[j]++;
					long long a;
					a=current_sum;
					if (j == 1) {
						current_sum+=stu[i].a;
					}
					if (j == 2) {
						current_sum+=stu[i].b;
					}
					if (j == 3) {
						current_sum+=stu[i].c;
					}
					dfs(i,current_num+1, current_sum, total);
					current_sum=a;
					haved[i]=false;
					each_stu_num[j]--;
				}
			}
		}
	}
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while (t--) {
		cin >> n;
		max_sum = 0;
		_max_sum = 0;
		flag = false;
		for (int i = 1; i <= n; i++) {
			cin >> stu[i].a >> stu[i].b >> stu[i].c;
			max_sum += max(max(stu[i].a, stu[i].b), stu[i].c);
			haved[i] = false;
		}//init
		if (n == 1) {
			cout << max_sum << "\n";
			continue;
		}//特判
		//上一学生编号   当前是在已选择学生人数  当前的满意度  总共要选的人数(边界) 
		dfs(0, 0, 0, n);
		cout << _max_sum << "\n";
	}
	return 0;
}
