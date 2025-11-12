#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	long long n,m=1;
	cin>>n;
	for (int i=1;i<=n;i++){
		m=m*i%998244353;
	}
	cout<<m%998244353;
    return 0;
}
