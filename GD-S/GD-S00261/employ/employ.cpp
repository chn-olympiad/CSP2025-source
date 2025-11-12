#include<bits/stdc++.h>
using namespace std;
int n;
long long p=998244353,ans=1;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		ans=ans*i%p;
	cout<<ans%p;
	return 0;
} 
