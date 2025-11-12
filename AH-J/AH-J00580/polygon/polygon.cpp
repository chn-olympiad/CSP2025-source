#include <bits/stdc++.h>
using namespace std;

const int N=3e3+5;
int n,a[N];

int main(){
	freopen ("polygon.in","r",stdin);
	freopen ("polygon.out","w",stdout);
	int maxn=-1,sum=0;
	cin >> n;
	if (n<3) {
		cout << 0;
		return 0;
	}
	for (int i=1;i<=n;i++){
		cin >> a[i];
		maxn=max(maxn,a[i]);
		sum+=a[i];
	}
	if (sum>(maxn*2)) cout << 1;
	else cout << 0;
	return 0;
}
