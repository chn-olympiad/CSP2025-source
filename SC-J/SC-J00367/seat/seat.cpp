#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

const int N=101;
int a[N];
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >> n >> m;
	int z;
	cin >> a[1];
	z=a[1];
	for(int i=2;i <= n * m;i++){
		cin >> a[i];
	}
	sort(a + 1,a + n * m + 1);
	for(int i=n * m;i >= 1;i--){
		if(a[i] == z){
			z=n * m + 1 - i;
			break;
		}
	}
	int h=((z - 1) % n) + 1,l=(z + n - 1) / n;
	if(l % 2 == 0){
		h=n + 1 - h;
	}
	cout << l << " " << h;
	return 0;
}