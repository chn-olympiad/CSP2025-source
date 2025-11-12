#include <bits/stdc++.h>
using namespace std;
int n,m,sum;
long long ans=1;
string s;
int c[505];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	cin >> s;
	for(int i = 0;i<s.size();i++){
		if(s[i]==1){
			sum++;
		}
	}
	for(int i = 1;i <= n;i++){
		cin >> c[i];
	}
	if(m==n){
		if(sum==n){
			for(int i = n;n >= 2;i--){
				ans*=i;
				ans%=998244353;
			}
			cout << ans;
			return 0;
		}else{
			cout << 0;
			return 0;
		}
	}
}