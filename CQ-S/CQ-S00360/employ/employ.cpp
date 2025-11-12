#include<bits/stdc++.h>
using namespace std;
string s;
long long n,m;//n天,n个应聘的人,m人被录取 
long long f[505],a[505];
long long dfs(long long i,long long d,long long gopeo,long long cnt){//gopeo指被拒绝的人 
	if(d>n || f[i]){
		return 0;
	}
	if(s[d-1] == '1' &&a[i] > gopeo){// 
		cnt++;
	}else{
		gopeo++;
	}
	if(cnt == m){
		return 1;
	}
	long long ans = 0;
	f[i] = 1;
	for(long long j = 1;j <= n;j++){
		if(f[j] == 0)
		ans += dfs(j,d+1,gopeo,cnt);
	}
	f[i] = 0;
	return ans;
} 
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >>n >>m;
	
	cin >> s;
	
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	int ans = 0;
	
	for(int j = 1;j <= n;j++){
		ans += dfs(j,1,0,0);
	}
	cout <<ans;
	return 0;
} 
