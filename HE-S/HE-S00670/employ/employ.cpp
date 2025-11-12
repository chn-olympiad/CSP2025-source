#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e4+100;
ll ans=1;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=m+1;i<=n;i++){
		ans=ans*i%998244353;
	}
	cout<<ans;
	return 0;
}
