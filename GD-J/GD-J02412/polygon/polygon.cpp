#include <bits/stdc++.h>
using namespace std;
int n;
int a[5005],b[5005];
int maxn = -1,sum = 0,sum1 = 0;
long long ans = 0;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++) 
	{
		cin >> a[i];
		maxn = max(maxn,a[i]);
		sum += a[i];
		b[i] += 2 * a[i];
	}
	sum1 = sum;
	sort(a + 1,a + n + 1);
	if(maxn == 1){
		cout << n - 2;
	}
	else if(n == 3){
		if((a[1] + a[2]) > a[3]){
			cout << 1;
		}
		else{
			cout << 0;
		}
	}
	else{
		if(sum > maxn * 2){
			cout << 1;
		}
		else{
			cout << 0;
		}
	}
}
