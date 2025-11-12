#include<bits/stdc++.h>
using namespace std;
int a[1000005];
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;
	cin>>n;
	int o=1;
	for(int i=1;i<=n;i++){
		o*=i;
	}
	int ans=0;
	for(int i=1;i<n;i++){
		int u=1;
		int f=1;
		for(int j=1;j<=i;j++){
			u*=j;
		}
		for(int j=1;j<=n-i;j++){
			f*=j;
		}
		ans+=o/(f*u);
		ans%=998244353; 
	}
	cout<<ans;

} 