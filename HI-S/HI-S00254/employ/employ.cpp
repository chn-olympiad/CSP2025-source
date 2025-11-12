#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,a[505],sum=0;
	cin>>n>>m;
	string s;
	cin>>s;
	for(int i = 1; i <= n; i++){
		cin>>a[i];
		if(a[i]) sum++;
	}
	if(s.find("0")!=string::npos){
		cout<<m;
		return 0;
	}
	if(sum < m) cout<<0;
	else{
		long long ans = 1;
		for(int i = 1; i <= n; i++){
			ans *= i;
			ans %= 998244353;
		}
		cout<<ans;
	}
	return 0;
}
