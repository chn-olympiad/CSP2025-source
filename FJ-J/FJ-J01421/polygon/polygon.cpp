#include<bits/stdc++.h>
#define int long long

using namespace std;

vector<int> lines;
const int MOD = 998244353;

int calc_ans(int n,int usen){
	int ans=0,base=1;
	for(int i=0;i<n-usen;i++){
		ans+=base;
		base *= n-i;
		ans%=MOD;
		base%=MOD;
	}
	return ans%MOD;
}

int dfs(vector<bool>used,int n,int target){
	int ans=0;
	if(target < 0){
		int usen=0;
		for(int i=0;i<n;i++){
			if(!used[i]){
				usen++;
			}
		}
		ans = calc_ans(n,usen>3?usen:3);
		return ans;
	}
	
	for(int i=0;i<n;i++){
		if(!used[i]){
			used[i]= 1;
			ans += dfs(used,n,target-lines[i]);
			ans %= MOD;
			used[i]=0;
		}
	}
	return ans;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,ans=0,temp;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>temp;
		lines.push_back(temp);
	}
	sort(lines.begin(),lines.end());
	
	vector<bool> used(n,0);
	for(int i=n-1;i>=2;i--){
		int target = lines[i];
		used[i]=1;
		ans+=dfs(used,n,target);
		ans%=MOD;
	}
	
	cout<<ans;
	
	return 0;
}
