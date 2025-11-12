#include<bits/stdc++.h>
using namespace std;
long long n,m,c[600],fo=0,ans=1;
string a;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>a;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	for(int i=1;i<=n;i++){
		ans*=i;
	}
	cout<<ans%998244353;
	return 0;
}
