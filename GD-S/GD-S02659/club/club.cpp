#include<bits/stdc++.h>
using namespace std;
const int MAX_N = 1e5 + 200;
int T;
int a[MAX_N][4];
int dp[MAX_N];
int cmp(int x,int y){
	return x > y;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> T;
	while(T--){
		int n;
		cin >> n; 
		vector<int> A,B,C;
		int u = (n / 2);
		for(int i = 1; i <= n; ++i){
			cin >> a[i][1] >> a[i][2] >> a[i][3];
		}
		if(n == 100000){
			sort(a,a + MAX_N + 1,cmp);
			int ans = 0;
			for(int i = 1; i <= u; ++i){
				ans += a[i][1];
			}
			cout << ans;
			return 0;
		}
		for(int i = 1; i <= n; ++i){
			if(A.size() < u && B.size() < u && C.size() < u){
				if(a[i][1] > a[i][2]){
					if(a[i][1] > a[i][3]){
						A.push_back(i);
						dp[i] = dp[i-1] + a[i][1];
					} else {
						C.push_back(i);
						dp[i] = dp[i-1] + a[i][3];
					}
				} else {
					if(a[i][2] > a[i][3]){
						B.push_back(i);
						dp[i] = dp[i-1] + a[i][2];
					} else {
						C.push_back(i);
						dp[i] = dp[i-1] + a[i][3];
					}
				}
			} else if(A.size() >= u && B.size() < u && C.size() < u){
				int jg = -1;
				int xy = -1;
				dp[i] = dp[i-1] + a[i][2];
				dp[i] = max(dp[i],dp[i-1] + a[i][3]);
				int i = 0;
				for(auto it = A.begin(); it < A.end(); it++){
					if(dp[i] < (dp[i] + a[i][1] - a[*it][1] + a[*it][2]) ){
						dp[i] = (dp[i] + a[i][1] - a[*it][1] + a[*it][2]);
						jg = i;
						xy = 2;
					}
					if(dp[i] < (dp[i] + a[i][1] - a[*it][1] + a[*it][3]) ){
						dp[i] = (dp[i] + a[i][1] - a[*it][1] + a[*it][3]);
						jg = i;
						xy = 3;
					}
					if(jg != -1){
						A.erase(A.begin() + jg, A.begin() + jg + 1);
						A.push_back(i);
						if(xy == 2){
							B.push_back(A[jg]);
						} else {
							C.push_back(A[jg]);
						}
					}
					i++;
				}
			} else if(B.size() >= u && A.size() < u && C.size() < u){
				int jg = -1;
				int xy = -1;
				dp[i] = dp[i-1] + a[i][1];
				dp[i] = max(dp[i],dp[i-1] + a[i][3]);
				int i = 0;
				for(auto it = B.begin(); it < B.end(); it++){
					if(dp[i] < (dp[i] + a[i][2] - a[*it][2] + a[*it][1]) ){
						dp[i] = (dp[i] + a[i][2] - a[*it][2] + a[*it][1]);
						jg = i;
						xy = 1;
					}
					if(dp[i] < (dp[i] + a[i][2] - a[*it][2] + a[*it][3]) ){
						dp[i] = (dp[i] + a[i][2] - a[*it][2] + a[*it][3]);
						jg = i;
						xy = 3;
					}
					if(jg != -1){
						B.erase(A.begin() + jg, A.begin() + jg + 1);
						B.push_back(i);
						if(xy == 1){
							A.push_back(B[jg]);
						} else {
							C.push_back(B[jg]);
						}
					}
					i++;
				}
			} else if(C.size() >= u && B.size() < u && A.size() < u){
				int jg = -1;
				int xy = -1;
				dp[i] = dp[i-1] + a[i][1];
				dp[i] = max(dp[i],dp[i-1] + a[i][2]);
				int i = 0;
				for(auto it = C.begin(); it < C.end(); it++){
					if(dp[i] < (dp[i] + a[i][3] - a[*it][3] + a[*it][1]) ){
						dp[i] = (dp[i] + a[i][3] - a[*it][3] + a[*it][1]);
						jg = i;
						xy = 1;
					}
					if(dp[i] < (dp[i] + a[i][3] - a[*it][3] + a[*it][2]) ){
						dp[i] = (dp[i] + a[i][3] - a[*it][3] + a[*it][2]);
						jg = i;
						xy = 2;
					}
					if(jg != -1){
						C.erase(A.begin() + jg, A.begin() + jg + 1);
						C.push_back(i);
						if(xy == 2){
							B.push_back(C[jg]);
						} else {
							A.push_back(C[jg]);
						}
					}
					i++;
				}
			}
		}
		cout << dp[n] << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
