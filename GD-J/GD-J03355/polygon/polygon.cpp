#include <bits/stdc++.h>
using namespace std;

long long int f[5001][5001];

int main(){
	
//	freopen("seat.in","r",stdin);
//	freopen("seat.out","w",stdout);
	
	int n = 0;
	cin>>n;
	vector<int> nums;
	for(int i = 0;i < n;i++){
		int aws = 0;
		cin>>aws;
		nums.push_back(aws);
	}
	
	sort(nums.begin(),nums.end());
	
	f[0][0] = 0;f[0][nums[0]] = 1;
	for(int i = 0;i < n;i++){
		for(int len = 0;len < 5000;len++){
				if(i == n)
					break;
				if(len <= 2 * nums[i + 1])
					f[i][len] = f[i-1][len];
				else f[i][len] = f[i-1][len + nums[i + 1]] + 1;
			}
		}
	long long int ans = -1;
	for(int i = 0;i < 5000;i++){
		//cout<<f[n - 1][i]<<" ";
		ans = max(ans,f[n - 1][i]);
	}
	ans = ans%998,244,353;
	cout<<ans;
	return 0;
}
