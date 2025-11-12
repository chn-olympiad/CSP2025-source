#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int n,ans=1;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n;
	for(int i=n;i;i--){
		ans=ans*i%mod;
	}
	cout<<ans;
	return 0;
}
/*
结庐在人境，而无车马喧。
问君何能尔？心远地自偏。
采菊东篱下，悠然见南山。
山气日夕佳，飞鸟相与还。
此中有真意，欲辨已忘言。
*/
