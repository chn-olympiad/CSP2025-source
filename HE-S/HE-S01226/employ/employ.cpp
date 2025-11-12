#include<bits/stdc++.h>
using namespace std;
int n,m,a[505];
int cnt,ans,flag;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	cin >> s;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	for(int k = 1;k <= n;k++){
		for(int j = k+1;j <= n;j++){
			flag = 0,cnt = 0;
			for(int i = 1;i <= n;i++){
				if(s[i]=='1' && flag<a[i]){
					cnt++;
				} else{
					flag++;
				}
			}
			if(cnt >= m){
				ans++;
			}
			swap(a[k],a[k+j]);
		}
	}
	cout << ans;
	return 0;
}
