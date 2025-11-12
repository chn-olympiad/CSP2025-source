#include <iostream>
#include <cstdio>
using namespace std;
string s;
int n,m,a[100],ans,cnt1,cnt0;
long long ans1;
bool flag = 1;
long long dfs(int cnt,int goal,int x,int unpass){
	int ans;
	if(cnt > goal)return 0;
	else if(cnt == goal)return 1;
	if(unpass>=a[x])return dfs(cnt,goal,x+1,unpass+1);
	if(cnt1){
		cnt1--;
		ans += dfs(cnt+1,goal,x+1,unpass);
		cnt1++;
		ans %=  998244353;
	}
	if(cnt0){
		cnt0--;
		ans += dfs(cnt,goal,x+1,unpass);
		cnt0++;
		ans %= 998244353;
	}
	return ans;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m >> s;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	for(int i = 0;i < s.size();i++){
		if(s[i]=='1')cnt1++;
		else cnt0++;
		if(a[i]==0)flag = 0;
	}
	if(flag){
		ans1 = 1;
		for(int i = 0;i < n;i++)ans1 *= (n-i);
		cout << ans1;
	}
	else{
		for(int i = m;i <= n;i++){
			ans1 += dfs(0,i,1,0);
			ans1 = ans1 % 998244353;
		}
		cout << ans1;
	}
	return 0;
}
