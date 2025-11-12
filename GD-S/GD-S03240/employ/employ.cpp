#include <iostream>
using namespace std;

long long ans;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	ans=1;
	for(;n;n--){
		ans=ans*n%998244353L;
	}
	cout<<ans;
	
	return 0;
}
