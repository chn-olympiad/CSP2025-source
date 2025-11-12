#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,b;
	string a;
	cin>>n>>m;
	cin>>a;
	for(int i=1;i<=n;i++) cin>>b;
	int sum=1;
	for(int i=1;i<=n;i++){
		sum*=i;
		sum=sum%998244353;
	}
	cout<<sum;
	return 0;
}
