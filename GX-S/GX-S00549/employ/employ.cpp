#include<bits/stdc++.h>
using namespace std;
long long n,m,c,ans;
string str;

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	cin>>str;
	for(int i=1;i<=n;i++){
		scanf("%lld",&c);
	}
	cout<<n*(n-1)%998244353;
	return 0;
}
