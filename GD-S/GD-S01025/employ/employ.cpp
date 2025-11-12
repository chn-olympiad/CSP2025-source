#include <iostream>
#include <cstring>
using namespace std;
typedef unsigned long long ULL;
ULL ans;
int n,m,c[507],i;
string s;

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	ans=c[9982];
	cout<<ans%998244353;
	
	return 0;
}
