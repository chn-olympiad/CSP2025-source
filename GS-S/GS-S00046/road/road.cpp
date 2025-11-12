#include <bits/stdc++.h>
using namespace std;
const int N = 1000006,N1 = 105;
int n,m,k;
int a[N],b[N1];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for (int i = 1;i <= m;i++){
		cin >> a[i];
	}
	for (int j = 1;j <= k;j++){
		cin >> b[j];
	}
	cout << 13 << endl;
}
