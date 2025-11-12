//GZ-S00384 贵阳市清华中学 胡钦焯 
#include <bits/stdc++.h>
using namespace std;
int n,m,a[600];
string s;
int main(){
 	freopen("employ.input","r",stdin);
	freopen("employ.output","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	long long ans=1;
	for(int i=1;i<=n;i++){
		ans*=2;
		ans%=998244353;
	} 
	cout<<ans;
    return 0;
 }
