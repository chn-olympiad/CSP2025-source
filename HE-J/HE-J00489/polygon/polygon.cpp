#include <bits/stdc++.h>
using namespace std;

long long n, a[5005], cnt=0;
bool cmp(int a, int b){
	return a>b;
}
int main(){
	
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	
	cin >> n;
	for(int i=0;i<n;i++) {
		cin >> a[i];
	}
	
	sort (a, a+n, cmp);
	
	for(int i=0;i<n-2;i++) {
		int aa = a[i], x = 0; /*"aa" is the max number in this range*/
		for(int j=i;j<n;j++) {
			x+=a[j];
			for (int k=0;k<=n-j-i; k++)if((x+a[j+k]-a[j]>aa) && j>=3) cnt++;
		}
	}
	cout << cnt;
	
	return 0;
} 
