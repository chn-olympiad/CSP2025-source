#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int n,m,c[10001],ans=1;
string s;
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++) cin>>c[i];
	for(int i=n;i>=1;i--) ans*=i,ans%=mod;//Æ­·ÖºÃ°É 
	cout<<ans<<"\n";
	
	return 0; 
}

