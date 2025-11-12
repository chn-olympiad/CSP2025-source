#include <iostream>
#include <string>
#include <vector>
using namespace std;

const long long MOD = 998244353;

vector<bool> used(501, false);
vector<int> now_list(501);
vector<vector<int>> all_list;

void all_A(vector<int> nums, int step) {
	int len = nums.size();
	
	if(step > len) {
		all_list.push_back(now_list);
		return;
	}
	
	for(int i = 0; i < len; i++) {
		if(!used[i]) {
			used[i] = true;
			
			now_list[step] = int(nums[i] - '0');
			all_A(nums, step + 1);
			
			used[i] = false;
		}
	}
}

int mian() {
	freopen("employ.in", "r", stdin);
	freopen("emplay.out", "w", stdout);
	
	int n, m;
	cin >> n >> m;
	
	string s;
	cin >> s;
	
	vector<bool> easy;
	int len = s.size();
	for(int i = 0; i < len; i++) {
		easy.push_back(int(s[i] - '0'));
	}
	
	vector<int> c(n);
	for(int i = 0; i < n; i++) {
		cin >> c[i];
	}
	
	all_A(c, 0);
	
	long long ans = 0;
	int len1 = all_list.size();
	for(int i = 0; i < len1; i++) {
		int count = 0;
		int now_no = 0;
		
		for(int j = 0; j < n; j++) {
			if(easy[j]) {
				count++;
			} else {
				now_no++;
			}
			
			if(now_no >= all_list[i][j + 1]) {
				j++;
			}
		}
		
		if(count >= m) {
			ans++;
			ans %= MOD;
		}
	}
	
	return 0;
}
