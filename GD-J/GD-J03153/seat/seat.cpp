#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	int a[105] = {};
	cin >> n >> m;
	int num = n * m;
	int s1;
	int ans;
	for(int i = 1;i <= num;i++){
		cin >> a[i];
		if(i == 1) s1 = a[i];
	}
	for(int i = 1;i <= num;i++){
		for(int j = 1;j <= num;j++){
			if(a[j] <= a[j + 1]){
				swap(a[j],a[j + 1]);
			}
		}
	}
	for(int i = 1;i <= num;i++){
		if(a[i] == s1){
			ans = i;
		}
	}
	cout << ans << "   ";
	int sum1,sum2;
	sum1 = (ans - 1) / m + 1;
	if(sum1 % 2 == 0){
		sum2 = n - (ans - 1) % n;
	}
	else{
		sum2 = (ans - 1) % n + 1;
	}
	cout << sum1 << ' ' << sum2;
	return 0;
}
