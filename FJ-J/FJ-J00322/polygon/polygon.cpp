#include<bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
int n;
int a[10005];
int cnt = 0;
int cnt1;

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
	}
	if(n <= 3){
		int max1 = max(max(a[1],a[2]),a[3]);
		if(a[1] + a[2] + a[3] > max1 * 2){
			cnt++;
		}
		cout<<cnt % MOD;
		return 0;
	}
	else{
		for(int l = 1;l <= n;l++){
			int sum = a[l];
			cnt1 = 1;
			int maxn = a[l];
			for(int r = l + 1;r <= n;r++){
				cnt1++;
				sum += a[r];
				maxn = max(maxn,a[r]);
				if(cnt1 > 3){
					if(sum > (2 * maxn)){
						cnt++;
					}	
				}
			}
		}
		cout<<cnt * 3 % MOD;
	}
	return 0;
}
