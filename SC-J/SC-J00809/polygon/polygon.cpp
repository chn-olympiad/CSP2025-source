#include <iostream>
using namespace std;
int n,ans=1;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;++i){
		ans=(ans*i)%998244353;
	}
	cout << ans;
	return 0;
}