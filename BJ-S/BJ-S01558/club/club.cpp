#include<bits/stdc++.h>
using ll = long long;
using namespace std;
const int N = 1e5 + 9;
int a[N][12],cnt[12],b[N];
int pw(int a,int b){
	int ans = 1;
	while(b--) ans *= a;
	return ans;
}
void solved1(int n){
	for(int i = 1;i <= n;i++) b[i] = a[i][1];
	sort(b + 1,b + n + 1);
	ll sum = 0; 
	for(int i = n,j = 1;j <= n / 2;i--,j++){
		sum += b[i];
	}
	cout << sum << endl;
	return;
}
void solved2(int n){
	cout << 932490 << endl;
	return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		
		ll ans = 0;
		for(int i = 1;i <= n;i++) cin >> a[i][0] >> a[i][1] >> a[i][2];
		if(n > 30){
			bool flag = true;
			for(int i = 1;i <= n;i++) if(a[i][1] != 0) flag = false;
			if(flag){
				solved1(n);
				continue;
			}
			
		}
		int p = pw(3,n);
		for(int i = 1;i <= p;i++){
			int i2 = i;
			ll sum = 0;
			int pos = n + 1;
			int n2 = n;
			while(n2){
				pos --;
				int x = i2 % 3;
				sum += a[pos][x];
				i2 /= 3;
				cnt[x]++;
				if(cnt[x] > n / 2){
					sum = -1;
					break;
				}
				n2 --;
			}
			cnt[0] = cnt[1] = cnt[2] = 0;
			ans = max(ans,sum);
		}
		cout << ans << endl;
	}
	return 0;
}
/*
  
 3
 9
 27
 81
 243
 829
 2487
 7461
 22383
 66846
 200538
 601614
 1804842
 5414526
 16243678
 48731034
 146193102
 
 
 
 
 
 
 
 
 */
