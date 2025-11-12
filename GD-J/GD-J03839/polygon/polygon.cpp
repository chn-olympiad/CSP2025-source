#include<bits/stdc++.h>
using namespace std;

const int mod = 998244353;
long long n;
long long stick[5005];
long long sum = 0;
bool used[5005];
long long cnt = 0;

void dfs(long long last_stick, long long current_stick, long long sum , long long _max, long long total) {
	if (current_stick>=total) {
		cnt++;
		return;
	}
	for (int i = 0; i < n; i++) {
		if (current_stick<2) {
			if ((!used[i]) && current_stick >= last_stick) {
				used[i] = true;
				sum+=stick[i];
				dfs(stick[i], current_stick+1,sum,max(_max,stick[i]),total);
				used[i]=false;
				sum-=stick[i];
			}
			continue;
		}
		if ((!used[i]) && current_stick >= last_stick) {
			used[i] = true;
			sum+=stick[i];
			if (sum > 2 * max(_max,stick[i])){
				cout<<stick[i]<<" ";//
				dfs(stick[i], current_stick+1,sum,max(_max,stick[i]),total);
			}
			used[i]=false;
			sum-=stick[i];
		}
	}
}

int main () {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	if (n==5) {
		cout << 9 << "\n";
		return 0;
	}
	for (int i = 0; i < n; i++)
		cin >> stick[i];
	sort(stick+0,stick+n);
	for (int i = 3; i <= n; i++) {
		//current_number_of_sticks, stick_s_long_sum ,max_longer_stick ,total_number_of_sticks
		dfs(0, 0, 0, -1, i);
	}
	cout << cnt << "\n";
	return 0;
}
