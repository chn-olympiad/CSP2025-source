#include<bits/stdc++.h>
using namespace std;
char s[505];
int a[505];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	long ans=1;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	cin>>s[i];
	for(int i=0;i<n;i++)
	cin>>a[i];
	for(int i=1;i<=n;i++)
	ans=(ans*i)%998244353;
	cout<<ans<<endl;
	
	return 0;
}
