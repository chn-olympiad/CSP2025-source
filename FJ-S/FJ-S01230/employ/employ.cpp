#include <bits/stdc++.h>
using namespace std;
int n,m;
int ans=1;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=n;i>=1;i--){
		ans=(ans*i)%998244353;
	}
	cout<<ans;
	return 0;
}

