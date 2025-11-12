#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k, sum=0, ans=0;
	cin >> n >> k;
	bool flag = false;
	vector<int>a(n+1);
	for(int i=1; i<=n; ++i){
		cin >> a[i];
		if(a[i]!=0 && a[i]!=1){
			flag = false;
		}
		sum^=a[i];
		if(sum==k){
			sum=0;
			ans++;
		}
	}
	if(!flag){
		int x = n-1;
		int ans = 0;
		for(int S = 0; S < (1<<x+1); ++S){
			map<int, bool> mp;
			int tot=0;
			for(int i=1; i<=x; ++i){
				if((1<<i) & S){
					mp[i] = 1;
					++tot;
				}
			}
			bool flag = true;
			int sum=0, cnt=0;
			for(int i=1; i<=n; ++i){
				sum^=a[i];
				if(mp[i]){
					if(sum!=k){flag = false;break;}
					sum=0;
				}
			}
			if(flag && sum==k){
				ans=max(ans, tot+1);
			}
		}
		cout << ans;
		return 0;
	}
	cout << ans;
	return 0;
}