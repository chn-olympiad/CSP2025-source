#include<bits/stdc++.h>
using namespace std;
int b[100005];
string a;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	long long a;
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		cin>>b[i];
		ans+=b[i];
	}
	long long l=pow(a,ans);
	cout<<l%998244353;
	return 0;
}
