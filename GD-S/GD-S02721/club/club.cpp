#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1010;
struct student{
	int num[5];
	/*
	operator()(const student  __x, const student __y) const{ 
		if (__x.num[1] != __y.num[1]) return __x.num[1] < __y.num[1];
		else if (__x.num[2] == __y.num[2]) return __x.num[3] < __y.num[3];
		else if (__x.num[3] == __y.num[3]) return __x.num[2] < __y.num[2];
		else if (abs(__x.num[2] - __y.num[2]) > abs(__x.num[3] - __y.num[3])) return __x.num[2]>__y.num[2];//num[2]差值大于num[3] 
		else return __x.num[3] > __y.num[3];
	 }
	 */
} x, y;
bool cmp(student x, student y){
	if (x.num[1] != y.num[1]) return x.num[1] < y.num[1];
	else if (x.num[2] == y.num[2]) return x.num[3] < y.num[3];
	else if (x.num[3] == y.num[3]) return x.num[2] < y.num[2];
	else if (abs(x.num[2] - y.num[2]) > abs(x.num[3] - y.num[3])) return x.num[2]>y.num[2];//num[2]差值大于num[3] 
	else return x.num[3] > y.num[3];
}
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t, cnt = 0;
	cin >> t;
	x.num[1];
	while (t--){
		int n;
		cin >> n;
		int a[n+10][5];
		vector <student> value[MAXN][5];//第一个为值，第二个为社团 
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= 3; j++){
				cin >> a[i][j];
			}
		}
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= 3; j++){
				student x;
				x.num[0] = 0, x.num[4] = 0;
				for (int k = 1; k <= 3; k++){
					x.num[k] = a[j][k];
				}
				value[a[i][j]][j].push_back(x);
			}
		}
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= 3; j++){
				for (int k = 1; k <= 3; k++){
					if (value[i][j].empty() == 0) cout << value[i][j][0].num[k] << " ";
				} 
			}
		}
		for (int i = 1010; i >= 0; i--){
			int is_empty = 0;
			for (int j = 1; j <= 3; j++){
				for (int k = 1; k <= 3; k++){
					if (value[i][j].empty() == 0){
						cnt += value[i][j][0].num[k];
					}
				}
				
				
			}
		}
		cout << cnt << endl;
	}
	return 0;
}
/*
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
/*
			if (value[i][1].empty()){
				is_empty++;
			} 
			if (value[i][1].empty()){
				is_empty+=2;
			}
			if (value[i][1].empty()){
				is_empty+=4;
			}
			if (is_empty == 0){
				continue; 
			} else if (is_empty == 1){
				for (int j = 0; j < value[i][1].size(); j++){
					for (int k = 0; k < value[i][1].size(); k++){
						if (cmp(value[i][1][j], value[i][1][k])){
							swap(value[i][1][j], value[i][1][k]);
						}
					}
				}
				cnt += value[i][1][0].num[1];
			} else if (is_empty == 2){
				for (int j = 0; j < value[i][1].size(); j++){
					for (int k = 0; k < value[i][1].size(); k++){
						if (cmp(value[i][1][j], value[i][1][k])){
							swap(value[i][1][j], value[i][1][k]);
						}
					}
				}
				cnt += value[i][2][0].num[2];
			} else if (is_empty == 4){
				for (int j = 0; j < value[i][1].size(); j++){
					for (int k = 0; k < value[i][1].size(); k++){
						if (cmp(value[i][1][j], value[i][1][k])){
							swap(value[i][1][j], value[i][1][k]);
						}
					}
				}
				cnt += value[i][3][0].num[3];
			} else if (is_empty == 3){
				for (int j = 0; j < value[i][1].size(); j++){
					for (int k = 0; k < value[i][1].size(); k++){
						if (cmp(value[i][1][j], value[i][1][k])){
							swap(value[i][1][j], value[i][1][k]);
						}
					}
				}
				cnt += max(value[i][1][0].num[1], value[i][2][0].num[2]);
			} else if (is_empty == 5){
				for (int j = 0; j < value[i][1].size(); j++){
					for (int k = 0; k < value[i][1].size(); k++){
						if (cmp(value[i][1][j], value[i][1][k])){
							swap(value[i][1][j], value[i][1][k]);
						}
					}
				}
				cnt += max(value[i][1][0].num[1], value[i][3][0].num[3]);
			} else if (is_empty == 6){
				for (int j = 0; j < value[i][1].size(); j++){
					for (int k = 0; k < value[i][1].size(); k++){
						if (cmp(value[i][1][j], value[i][1][k])){
							swap(value[i][1][j], value[i][1][k]);
						}
					}
				}
				cnt += max(value[i][2][0].num[2], value[i][3][0].num[3]);
			} else if (is_empty == 7){
				for (int j = 0; j < value[i][1].size(); j++){
					for (int k = 0; k < value[i][1].size(); k++){
						if (cmp(value[i][1][j], value[i][1][k])){
							swap(value[i][1][j], value[i][1][k]);
						}
					}
				}
				cnt += max(value[i][1][0].num[1], max(value[i][2][0].num[2], value[i][3][0].num[3]));
			}
			*/
