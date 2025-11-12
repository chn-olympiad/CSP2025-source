#include<bits/stdc++.h>
using namespace std;
int a[5005];

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,xb = 1,sums = 0;
	cin >> n;
	for(int i=1 ; i<=n ; i++){
		cin >> a[i];
		if(a[xb] < a[i]) xb = i;
		sums += a[i];
	}
	if(sums > 2*a[xb]) cout << 1;
	else cout << 0;
	return 0;
}
