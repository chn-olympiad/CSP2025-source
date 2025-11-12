#include<bits/stdc++.h>                                                                                                                                                                                                                                                                                                             /*/*#include<iostream>#include<cstdio>#include<cmath>#include<algorithm>#include<ctring>*/
#define MOD 998244353
using namespace std;
unsigned long long n,m,c[501],ans=1;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=0;i<n;++i){
		cin>>c[i];
		ans*=c[i];
		ans=ans%MOD;
	}
	cout<<ans;
	return 0;
}
