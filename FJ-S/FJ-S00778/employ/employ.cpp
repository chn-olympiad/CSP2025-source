#include <iostream>
using namespace std;
int n;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n;
	long long res=1;
	for (long long i=1;i<=n;i++){
		res=res*i%998244353;
	}
	cout<<res;
	return 0;
}
