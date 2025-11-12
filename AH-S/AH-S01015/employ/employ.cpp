
#include<bits/stdc++.h>
using namespace std;

const int MOD=998244353;
int n;
long long ans=1;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	cin>>n;
	
	for(int i=n;i>1;i--)
		ans*=i,ans%=MOD;
		
	cout<<ans;
	
	return 0;
}
