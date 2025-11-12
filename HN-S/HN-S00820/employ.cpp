#include<bits/stdc++.h>
using namespace std;
#define m 998244353
int n;
unsigned long long ans=1;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		ans*=i;
		ans%=m;
	}
	cout<<ans;
	return 0;
}
/*
 €€€€   €€€€  ¡ê¡ê¡ê 
€      €      ¡ê
€      €      ¡ê¡ê¡ê
€      €      ¡ê
 €€€€   €€€€  ¡ê
*/

