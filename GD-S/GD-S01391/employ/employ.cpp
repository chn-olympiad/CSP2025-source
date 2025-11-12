#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	long long ans=1;
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		ans*=i;
		ans%=998244353;
	}
	cout<<ans;
	return 0;
}
