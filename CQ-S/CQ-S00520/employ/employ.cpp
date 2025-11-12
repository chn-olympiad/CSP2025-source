#include<bits/stdc++.h>
#define ll long long
#define M 998244353
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int a,b;
	cin>>a>>b;
	ll ans=1;
	for(int i=2;i<=a;i++)ans=(ans*i%M);
	cout<<ans;
	/*ףCQ-J00493 RP++; ףCQ-J00493 RP++; 
	ףCQ-J00493 RP++; ףCQ-J00493 RP++; 
	ףCQ-J00493 RP++; ףCQ-J00493 RP++; */
	return 0;
}
 
