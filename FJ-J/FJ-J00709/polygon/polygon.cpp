#include <bits/stdc++.h>
using namespace std;
int a[5005];
long long cnt=2;
long long sum;
int ans;

int main(){
	freopen("polygon.out","w",stdout);
	int n;
	cin >> n;
	for(int i=1; i<=n; i++){
		cin >> a[i];
	}
	if(n == 3){
		sort(a+1,a+n+1);
		if(a[1] + a[2] + a[3] > a[3] * 2){
			cout << 1;
			return 0;
		}else{
			cout << 0;
			return 0;
		}
	}
	freopen("polygon.in","r",stdin);
	sort(a+1,a+n+1);
	while(cnt != n){
		cnt++;
		for(int i=cnt-1; i<n; i++){
			for(int k=i-cnt+2; k<=i; k++){
				sum += a[k];
			}
			for(int j=i+1; j<=n; j++){
				sum += a[j];
				if(sum > a[j] * 2){
					ans++;
				}
			}
		}
		ans %= 998244353;
	}
	cout << ans;
    return 0;
}

