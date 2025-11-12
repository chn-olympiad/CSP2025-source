#include<bits/stdc++.h>
using namespace std;
int a[5010];
int b[5010];
set<vector<int>> se;

bool f(vector<int> nums){
	int le = nums.size();
	int sum = 0;
	for(int i=1;i<le;++i){
		sum += a[nums[i]];
	}
	if(sum > a[nums[0]]) return true;
	return false;
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin >> n;
	for(int i=0;i<n;++i) cin >> a[i];
	for(int i=0;i<n;++i) b[i] = i;
	
	sort(a,a+n,greater<int>());
	
	int ans = 0;
	
	vector<int> tmpp;
	for(int i=0;i<n;++i){
		tmpp.push_back(i);
	}
	se.insert(tmpp);
	
	do{
		for(int i=3;i<n;++i){
			vector<int> tmp;
			bool flag = true;
			for(int j=0;j<i;++j){
				if(j!=i-1){
					if(b[j] >= b[j+1]) {flag = false;break;}
				} 
				tmp.push_back(b[j]);
			}
			if(flag) se.insert(tmp);
		}
	}while(next_permutation(b,b+n));
	
	
	for(vector<int> i:se){
		if(f(i) == 1) ans = (ans+1) % 998244353;
	}
	cout<<ans;
	return 0; 
}
