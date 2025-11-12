#include<bits/stdc++.h>
using namespace std;
int t;
int a[100010][5];
int x[100010];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while(t--){
		int klz = 0;
		int n;
		cin >> n;
		int len = n/2;
		for(int i = 1;i<=n;i++){
			for(int j = 1;j<=3;j++){
				cin >> a[i][j];
			}
		}
		for(int i = 1;i<=n;i++){
			x[i] = a[i][1];
		}
		sort(x+1,x+n+1);
//		for(int i = 1;i<=n;i++){
//			cout << x[i] << ' ';
//		}
		for(int i = len;i>=1;i--)
			klz += x[n-i+1];
		cout << klz << '\n';
	}
	return 0;
}

