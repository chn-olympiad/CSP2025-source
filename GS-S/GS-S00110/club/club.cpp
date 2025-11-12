#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

void generate_cases(set<vector<int>> &all_cases, vector<int> &count_arr, vector<int> &single_case, int n, int index) {
	if (index == n) {
		all_cases.insert(single_case);
	} else {
		for (int i = index; i < n; ++i) {
			for (int j = 0; j < 3; ++j) {
				if (count_arr[j] < n / 2) {
					single_case.push_back(j);
					count_arr[j] += 1;
					generate_cases(all_cases, count_arr, single_case, n, index + 1);
					count_arr[j] -= 1;
					single_case.pop_back();
				}	
			}
		}
	}
}

int main() {
//    freopen("./club2.in", "r", stdin);
//    freopen("./club2.out", "w", stdout);
    int t;
    cin >> t;
    while (t > 0) {
        t--;
        int n;
        cin >> n;
        int max_member = n / 2;
        if (n <= 4) {
	        vector<vector<int>> arr(n, vector<int>(3, 0));
	        for (int i = 0; i < n; i++) {
	            cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
	        }        	
        	set<vector<int>> all_cases;
        	vector<int> single_case = {};
        	vector<int> count_arr(3, 0);
        	generate_cases(all_cases, count_arr, single_case, n, 0);
			long long ans = 0;
			for (auto &s_case: all_cases) {
				long long temp_ans = 0;
				for (int i = 0; i < n; ++i) {
        			temp_ans += arr[i][s_case[i]];
				}
				ans = max(temp_ans, ans);
			}
			cout << ans << endl;
		} else {
	        vector<vector<int>> arr(3 * n, vector<int>(3, 0));
	        for (int i = 0; i < 3 * n; i += 3) {
	            cin >> arr[i][0] >> arr[i + 1][0] >> arr[i + 2][0];
	            arr[i][1] = i / 3;
	            arr[i + 1][1] = i / 3;
	            arr[i + 2][1] = i / 3;
	            arr[i][2] = 0;
	            arr[i + 1][2] = 1;
	            arr[i + 2][2] = 2;
	        }
	        sort(arr.begin(), arr.end());
	        long long ans = 0;
	        for (int j = 3 * n - 1; j >= 0; --j) {
	        	vector<bool> selected(n, false);
	        	vector<int> member_count(3, 0);
	        	long long temp_ans = 0;
				for (int i = j; i >= 0; --i) {
		            int member = arr[i][1];
		            int club = arr[i][2];
		            if (member_count[club] < max_member && (!selected[member])) {
		                temp_ans += arr[i][0];
		                member_count[club]++;
		                selected[member] = true;
		            }
		        }
		        bool all_selected = true;
		        for (int q = 0; q < n; ++q) {
		        	all_selected = all_selected && selected[q];
				}
				if (all_selected) {
					ans = max(ans, temp_ans);
				}
			}
			cout << ans << endl;	
		}
    }
    return 0;
}
