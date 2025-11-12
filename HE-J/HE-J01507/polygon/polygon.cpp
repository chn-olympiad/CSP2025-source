#include<bits/stdc++.h>
using namespace std;
long long a[10005];
long long n,cnt,j;
long long jc(int h) {
	if (h == 1) return 1;
	return jc(h-1)*h;
}
int main () {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for (int i=1;i<=n;i++) {
		cin >> a[i];
	}	
	long long sum=a[1]+a[2]+a[3];
	int maxn=max(a[1],max(a[2],a[3]));
	if (maxn*2 < sum)    cnt++;
	cout << cnt%998244353;
	return 0;
} 
