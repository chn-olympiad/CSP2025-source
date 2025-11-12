#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m,ans=1;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1,t;i<=n;i++){
		cin>>t;
	}
	for(int i=1;i<=n;i++){
		ans*=i;
		ans%=mod;
	}
	cout<<ans;
	return 0;
}
//Ren5Jie4Di4Ling5%
