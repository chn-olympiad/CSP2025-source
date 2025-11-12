//GZ-S00452 贵阳实验三中 闫张玴 
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+20;
int n, T, bumen=0;
bool flag=false;
int a[N][4], people[4]={}, kuisun[4], weizhi[N][3]={};
int main() {
	
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	cin >> T;
	while(T--) {
		int sum=0;
		cin >> n;
		for(int i = 1; i <= n; i++) {
			cin >> a[i][1] >> a[i][2] >> a[i][3];
		}
		for(int i = 1; i <= n; i++) {
			sum+=max(max(a[i][1], a[i][2]), a[i][3]);
	/*		if(max(max(a[i][1], a[i][2]), a[i][3]) == a[i][1]) {
				people[1]++;
				int tmp = people[1];
				weizhi[tmp][1] = i;
				bumen=1;
			}else if(max(max(a[i][1], a[i][2]), a[i][3]) == a[i][2]) {
				people[2]++;
				int tmp = people[2];
				weizhi[tmp][2] = i;
				bumen=2;
			}else {
				people[3]++;
				int tmp = people[3];
				weizhi[tmp][3] = i;
				bumen=3;
			}
			if(people[bumen]>n/2) {
				people[bumen]--;
				sum = sum - max(max(a[i-1][1], a[i-1][2]), a[i-1][3]);
				int r=1;
				int minn=2*1e4, minnweizhi, minnxiangmu;
				for(int c = weizhi[r][bumen]; r <= n/2; r++) {
					kuisun[1] = a[c][bumen]-a[c][1], kuisun[2] = a[c][bumen] - a[c][2], kuisun[3] = a[c][bumen] - a[c][3];
					if(kuisun[1] && kuisun[2]) {
						minn=min(minn, min(kuisun[1], kuisun[2]));
					} else if(kuisun[2] && kuisun[3]) {
						minn=min(minn, min(kuisun[2], kuisun[3]));
					} else if(kuisun[1] && kuisun[3]) {
						minn=min(minn, min(kuisun[1], kuisun[3]));
					}
					if(minn == kuisun[1] || minn == kuisun[2] || minn == kuisun[3]) minnweizhi=c;
					if(minn == kuisun[1]) minnxiangmu=1;
					else if(minn == kuisun[2]) minnxiangmu=2;
					else if(minn == kuisun[3]) minnxiangmu=3;
				}
				kuisun[0] = a[minnweizhi][bumen] - a[minnweizhi][minnxiangmu];
				sum -= kuisun[0];
				people[minnxiangmu]++;
			}*/
		}
		cout << sum << endl;
	}
	
	return 0;
}
