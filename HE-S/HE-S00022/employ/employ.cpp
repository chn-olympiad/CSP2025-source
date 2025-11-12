#include <bits/stdc++.h>
using namespace std;
long long  n,m;string s;int c[100005],ans=1;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(long long i=1;i<n;i++){
		cin>>c[i];
	}
	for(long long i=1;i<labs(n-m);i++){
		ans*=i;
	}
	ans=((long long)pow(ans,labs(n-m)))%998244353;
	cout<<ans;
	return 0;
}
