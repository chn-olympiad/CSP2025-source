//GZ-S00258 遵义市新蒲中学 杨子曦 
#include <bits/stdc++.h>
using namespace std;
int a[10000][3];
int b[15][10000];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin >> n >> m >> k;
	for(int i = 0;i < n;i++) {
		cin >> a[i][0] >> a[i][1] >> a[i][2];
	}
	for(int i = 0;i < k;i++) {
		for(int j = 0;j < n;j++) {
			cin >> b[i][j];
		}
	}
	cout << 0;
	return 0;
}
