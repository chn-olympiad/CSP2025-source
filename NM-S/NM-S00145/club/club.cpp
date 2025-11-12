#include <bits/stdc++.h>
using namespace std;

int n[100000][3];

int main(){
	int t;
	cin >> t;
	for(int i=0;i<t;i++){
		int m,s=0;
		int dp[100000][3]={0};
		cin >> m;
		for(int j=1;j<=3;j++){
			for(int k=1;k<=m;k++){
				cin >> n[j][k];
			}
		}
		for(int j=1;j<=3;j++){
			s=s+max(max(a[j][1],a[j][2]),max(a[j][2],a[j][3]));
		}
		cout << dp[m][3] << endl;
	}

	return 0;
}