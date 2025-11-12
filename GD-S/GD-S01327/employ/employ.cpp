#include<bits/stdc++.h>
using namespace std;
int n,m,ans,cnt,sum = 1,c[505],ss;
bool ff[505];
string s;
void dfs(int all,int now,int last){
	if(all > n){
		if(now >= m) ss++;
		ss %= 998244353;
		return;
	}
	for(int i=1;i<=n;i++){
		if(!ff[i]){
			ff[i] = 1;
			if(all-last >= c[i]) dfs(all+1,now+1,all);
			else dfs(all+1,now,last);
			ff[i] = 0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	cin >> s;
	for(int i=1;i<=n;i++){
		cin >> c[i];
		if(c[i] == 0) cnt++;
	}
	if(n<=18){
		dfs(1,0,0);
		cout << ss;
		return 0;
	}
	for(int i=0;i<n;i++){
		if(s[i] == '1') ans++;
	}
	if(ans == n){
		if(cnt <= n-m){
			for(int i=n;i>=1;i--){
				sum *= i;
				sum %= 998244353;
			}
		}else sum = 0;
		cout << sum;
		return 0;
	}
} 
