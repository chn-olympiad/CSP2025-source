#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int n;
vector<int>a;
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	a.resize(n+1,0);
	if(n<=3){
		cin>>a[1]>>a[2]>>a[3];
		if(a[1]+a[2]+a[3]>2*max({a[1],a[2],a[3]}))cout<<1;
		else cout<<0;
		return 0;
	}
	else{
		int ans=0,ans2=1;
		for(int i=3;i<=n;i++){
			ans2=1;
			for(int j=n,k=1;k<=i;k++,j--)ans2=(ans2*j)%mod;
			for(int k=1;k<=i;k++)ans2=(ans2/k)%mod;
			ans=(ans+ans2)%mod;
		}
		cout<<ans;
	}
	return 0;
}
