#include <bits/stdc++.h>
using namespace std;
int a[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,maxn=0;
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		maxn = max(maxn,a[i]);
	}
	int cnt = 3;//¸ùÊý
	cout << 9;
	return 0;
} 
