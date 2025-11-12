#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	long long n,m=1;
	cin>>n;
	for(long long i=1;i<=n;i++){
		m*=i;
		m%=998244353;
	}
	cout<<m;
	return 0;
}
