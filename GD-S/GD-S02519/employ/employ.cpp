#include<bits/stdc++.h>
#define int long long
#define MAXN
using namespace std;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;cin>>n>>m;int ans=1,sum=n;
	string s;cin>>s;
	for(int i=1;i<=n;i++){
		int x;scanf("%lld",&x);
		if(!x)sum--;
	}
	if(sum<m)cout<<"0\n";
	else {
		for(int i=1;i<=sum;i++)ans=ans*i%998244353;
		cout<<ans;
	}
	return 0;
}

