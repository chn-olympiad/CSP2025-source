#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("employ.in","r",stdin); 
	freopen("employ.out","w",stdout); 
	int m,n,ans=1,zj=0;
	cin>>n>>m;
	string s;
	cin>>s;
	for(int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		if(x) zj++;
	}
	if(zj<m)
	{
		cout<<0;
		return 0;
	}
	while(zj-1)
	{
		int a=zj%998244353;
		ans*=a;
		ans%=998244353;
		zj--;
	}
	cout<<ans;
	return 0;
}
