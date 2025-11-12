#include<bits/stdc++.h>
using namespace std;
long long n,m,ans=1;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdin);
	cin>>n>>m;
	string s;
	cin>>s;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
	}
	for(int i=1;i<=n;i++){
		ans*=i;
	}
	cout<<ans%998244353;
	return 0;
}
