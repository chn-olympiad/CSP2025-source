#include <bits/stdc++.h>
using namespace std;
long long n,sum=1;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		sum*=i;
		sum%=998244353;
	}
	cout<<sum;
	return 0;
}
