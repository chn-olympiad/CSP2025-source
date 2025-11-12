#include <bits/stdc++.h>
using namespace std;
int n,m;
long long ans=1;
int mo= 998244353;
bool s[505];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	while(m--){
		ans*=(m+1);
		ans%=mo;
	}
	cout<<ans;
	return 0;
}
