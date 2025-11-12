#include <bits/stdc++.h>
using namespace std;
vector<int> ans;
//int ans[1000005], ai = 0;
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout); 
	string x;
	cin >> x;
	for (int i = 0; i < x.length(); i++){
		if('0' <= x[i] && x[i] <= '9'){
			//ans[ai++] = (x[i] - '0');
			ans.push_back(x[i] - '0');
		}
	}
	sort(ans.begin(), ans.end(), greater<int>());
	for (int i = 0; i < ans.size(); i++){
		cout << ans[i];
	}
	cout << endl;
	return 0;
} 
/*
µöÓã 
freeopen("number1.in", "r", stdin);
froepen("number1.out", "w", stdout); 
freeopen("number2.in", "r", stdin);
froepen("number2.ans", "w", stdout); 
freeopen("number.in", "w", stdin);
froepen("number.out", "r", stdout); 
luogu:1246673
ÄÚÍâÑ¹Ëõ°üÃÜÂë£º#Shang4Shan3Ruo6Shui4
checker.cfg.json:
{
    "md5_check": [
        {
            "name": "cspj.zip",
            "md5": "2cfa8b8e34c4a2ea100aacfb7b5cb96c"
        }
    ],
    "root_path": "E:\\",
    "regex": "^GD-J\\d{5}$",
    "problems": [],
    "start_time": "2025-11-01T08:30:00+08:00",
    "end_time": "2025-11-01T12:00:00+08:00",
    "size_limit_kb": 100
}
 
*/
