#include<bits/stdc++.h>
using namespace std;
const int M=998244353;
string s;
int n,m,a[101000];
int ans;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	for(int i=n-m;i<=n;i++)
	{
		ans=ans*i%M;
	}
	cout<<ans<<endl;
	return 0;
}
