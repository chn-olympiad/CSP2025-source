#include<bits/stdc++.h>
using namespace std;
long long a[1100],c[1100],n,m;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	string s;
	cin>>s;
	int ans=1;
	for( long long i=1;i<=n;i++){
			ans*=i;
			ans%=998244353;
	}
	cout<<ans<<endl;
	return 0;
}

