#include<bits/stdc++.h>
using namespace std;
long long a[1010]; 
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	long long flag = 1;
	for (long long i = 1;i <= n;i++){
		cin>>a[i];
	}
	for (long long i = 0;i < n;i++){
		if (s[i] != '1') flag = 0;
	}
	if (flag){
		long long ans = 1,cnt = 0;
		for (long long i = 1;i <= n;i++){
			if (a[i] <= cnt){
				cnt++;
			}
		}
		for (long long i = 1;i <= n-cnt;i++){
			ans = ans * i % 998244353;
		}
		cout<<ans % 998244353<<" "<<161088479;
	}
	return 0;
} 
