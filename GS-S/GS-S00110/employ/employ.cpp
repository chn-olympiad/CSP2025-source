#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

void generate_cases(set<vector<int>> &all_cases, vector<int> &single_case, int n, int index) {
	if (index == n) {
		all_cases.insert(single_case);
	} else {
		for (int i = index; i < n; ++i) {
				single_case.push_back(i);
				generate_cases(all_cases, count_arr, single_case, n, index + 1);
				single_case.pop_back();
			}	
		}
	}
}

int main() {
//    freopen("./employ1.in", "r", stdin);
//    freopen("./employ1.out", "w", stdout);
    int n, m;
    cin >> n >> m;
	string ss;
	cin >> ss;
    vector<int> patients(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> patients[i];
    }        	
	set<vector<int>> all_cases;
	vector<int> single_case = {};
	generate_cases(all_cases, single_case, n, 0);
	long long ans = 0;

	cout << all_case.size() << endl;
    return 0;
}
