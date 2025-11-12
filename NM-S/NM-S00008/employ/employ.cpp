#include<bits/stdc++.h>
using namespace std;
int c[501],m,n,ans=1;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	string s;
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++) cin>>c[i];
	for(int i=n-m+1;i<=n;i++)
	    ans=(ans*i)%998244353;
	cout<<ans;   
	return 0;          
}
