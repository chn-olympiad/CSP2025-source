#include <bits/stdc++.h>
using namespace std;
int a[1000];
int main(){
	freopen("enpoly.in","r",stdin);
	freopen("enpoly.out","w",stdout);
	int n,m;cin>>n>>m;
	string s;cin>>s;
	for(int i=1;i<=1;i++) cin>>a[i];
	long long ans=1;
	for(int i=2;i<=m;i++){
		ans*=i%998244353;
	}
	cout<<ans%998244353;
	return 0;
}
