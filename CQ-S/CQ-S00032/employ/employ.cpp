#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,ans=1;
	cin>>n;
	for(int i=1;i<=n;i++) ans=ans*i%998244353;
	cout<<ans;

	return 0;
}
/*
AFO于2025.11.1
OI:2021.11~2025.11
四年OI一场空 
*/
