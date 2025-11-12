#include <bits/stdc++.h>
using namespace std;

struct student{
	int x,y,z,mx;
};
bool cmp(student a,student b){
	int mxa,mxb;
	if(a.mx == 0) mxa = a.x;
	else if(a.mx == 1) mxa = a.y;
	else mxa = a.z;
	if(b.mx == 0) mxb = b.x;
	else if(b.mx == 1) mxb = b.y;
	else mxb = b.z;
	return mxa > mxb;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<student> a(n+1);
		int use[100009][3];
		long long dp[100009];
		for(int i=0;i<=n;i++){
			dp[i] = 0;
			use[i][0] = use[i][1] = use[i][2] = 0;
		}
		for(int i=1;i<=n;i++){
			cin >> a[i].x >> a[i].y >> a[i].z;
			if(a[i].x >= a[i].y && a[i].x >= a[i].z) a[i].mx = 0;
			else if(a[i].y >= a[i].z) a[i].mx = 1;
			else a[i].mx = 2;
		}
		sort(a.begin()+1,a.end(),cmp);
		for(int i=1;i<=n;i++){
			if(use[i-1][a[i].mx]+1 <= n/2){
				if(a[i].mx == 0) dp[i] = dp[i-1] + a[i].x;
				else if(a[i].mx == 1) dp[i] = dp[i-1] + a[i].y;
				else dp[i] = dp[i-1] + a[i].z;
				use[i][0] = use[i-1][a[i].mx];
				use[i][1] = use[i-1][a[i].mx];
				use[i][2] = use[i-1][a[i].mx];
				use[i][a[i].mx]++;
			}else{
				int tp;
				if(a[i].mx == 0){
					if(a[i].y >= a[i].z) tp = 1;
					else tp = 2;
					dp[i] = dp[i-1] + max(a[i].y,a[i].z);
				}else if(a[i].mx == 1){
					if(a[i].x >= a[i].z) tp = 0;
					else tp = 2;
					dp[i] = dp[i-1] + max(a[i].x,a[i].z);
				}else{
					if(a[i].x >= a[i].y) tp = 0;
					else tp = 1;
					dp[i] = dp[i-1] + max(a[i].x,a[i].y);
				}
				use[i][0] = use[i-1][a[i].mx];
				use[i][1] = use[i-1][a[i].mx];
				use[i][2] = use[i-1][a[i].mx];
				use[i][tp]++;
			}
		}
		cout << dp[n] << endl;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
