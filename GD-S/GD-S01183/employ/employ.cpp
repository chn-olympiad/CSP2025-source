#include<bits/stdc++.h>
using namespace std;
int n;long long ans=1;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++) (ans*=(long long)i)%=998244353;
	cout<<ans;
	return 0;
}
