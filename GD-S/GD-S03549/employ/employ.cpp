#include<iostream>
using namespace std;
//这是第四题，如你所见，和J组T4一样的题型，毛都不会啊 
long long ans=1,n,m,mod=998244353;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=2;i<=n;i++){
		ans=(ans*i)%mod;
	}
	cout<<ans;
	return 0;	
} 
