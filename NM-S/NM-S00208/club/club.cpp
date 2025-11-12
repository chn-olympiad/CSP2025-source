#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int T;
int main() {
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);

	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);

	cin>>T;
	while(T--) {
		int n;
		int a[N][3];
		int sum;
		int b[4] = {};//部门人数
		int goal[N];
		int se_goal[N];
		int th_goal[N];

		cin>>n;
		for(int i=0; i<n; i++) {
			cin>>a[i][1]>>a[i][2]>>a[i][3];
//			int ma = max(max(max(a[i][1],a[i][2]),a[i][3]),ma);
			if(a[i][1]>a[i][2]) {
				th_goal[i] = 2;
				if(a[i][1]>a[i][3])
					goal[i] = 1,se_goal[i] = 3;
				else
					goal[i] = 3,se_goal[i] = 1;
			} else if(a[i][2]>a[i][3]) {
				th_goal[i] = 3;
				if(a[i][2]>a[i][1])
					goal[i] = 2,se_goal[i] = 1;
				else
					goal[i] = 1,se_goal[i] = 2;
			}
		}
		int full = n/2;
		for(int i=0; i<n; i++) {
			if(b[goal[i]]<full) {//第一理想
				b[goal[i]]++;
				sum+=a[i][goal[i]];
			} else {
				if(b[se_goal[i]]<full) {//第二理想
					b[se_goal[i]]++;
					sum+=a[i][se_goal[i]];
				}
				else{
					b[th_goal[i]]++;//第三理想
					sum+=a[i][th_goal[i]];
				}
			}

		}
		cout<<sum<<endl;
	}
	cout<<endl;
	return 0;
}
//RE or TLE
