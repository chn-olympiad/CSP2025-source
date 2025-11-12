#include<bits/stdc++.h>
using namespace std;
string s;
long long n,m,ans = 0;
long long c[510],a[510];
long long tong[510];
void dfs(long long x){
	if(x == n + 1){
		/*
		for(int i = 1;i <= n;i++){
			cout << a[i] << " ";
		}
		cout << endl;
		*/
		long long cnt = 0,cnt2 = 0;
		for(int i = 1;i <= n;i++){
			if(s[i - 1] == '0'){
				cnt++;
			}else{
				if(c[a[i]] <= cnt){
					cnt++;
				}else{
					cnt2++;
				}
			}
		}
		//cout << cnt << endl;
		if(cnt2 >= m)ans++;
		return;
	}
	for(int i = 1;i <= n;i++){
		if(!tong[i]){
			tong[i] = 1;
			a[x] = i;
			dfs(x + 1);
			tong[i] = 0;
		}
	}
	return;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	cin >> s;
	for(int i = 1;i <= n;i++)cin >> c[i];
	dfs(1);
	cout << ans << endl;
	return 0;
}
