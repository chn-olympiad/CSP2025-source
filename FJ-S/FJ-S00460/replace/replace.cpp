#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	long long ans=1;
	for(int i=1;i<=100;i++){
		ans=(ans*i)%998244353;
		
	}cout<<ans<<endl;
	return 0;
}
