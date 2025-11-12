#include <bits/stdc++.h>
using namespace std;
long long n;
int stick[5005];
long long ans = 0;

int s[5005];
long long tmp = 1;

dfs(int step,long long sum){
	if (step == n+1){
		if (tmp - 1 < 3){
			return 0;
		}
		
		sort(s+1,s+tmp - 1);
		
		if (sum > s[tmp - 1]*2){
			ans++;
		}
		
		return 0;
	}
	
	dfs(step+1,sum);
	
	s[tmp] = stick[step];tmp++;
	dfs(step+1,sum + stick[step]);
	tmp--;s[tmp] = 0;
	
	return 0;
}
int main(){
	freopen("polygon.in","r",stdin);
	
	freopen("polygon.out","w",stdout); 
	cin >>n;
	for (long long i= 1;i <= n;i++){
		cin >>stick[i];
	}
	
	dfs(1,0);
	cout<<ans;
	return 0;
}
