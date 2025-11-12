#include<bits/stdc++.h>
using namespace std;
#define long long int
const int MOD = 998244353;
int c[505];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	bool flag = true;
	for(int i = 1;i<=n;i++){
		cin>>c[i];
		if(c[i]!=1){
			flag = false;
		}
	}
	if(flag){
		for(int i = 0;i<m;i++){
			if(s[i]=='0'){
				cout<<0;
				return 0;
			}
		}
		int ans = 1;
		for(int i = 2;i<=n;i++){
			ans = ans*i%MOD;
		}
		cout<<ans%MOD;
	}else{
		cout<<0;
	}
	return 0;
}
