#include<bits/stdc++.h>
using namespace std;
char a;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	long long n,m,ans=0;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a;
		if(a=='1')
		{
			ans++;
		}
		ans%=998244353;
	}
	cout<<ans;
	return 0;
}
