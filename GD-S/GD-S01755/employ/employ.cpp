#include <bits/stdc++.h>
using namespace std;
const long long mmodd=998244353;
long long n,m,c[500],ans=1,tmp;
string s;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
		if(c[i]!=0)
		{
			tmp++;
		}
	}
	for(int i=1;i<=tmp;i++)
	{
		ans=(ans*i)%mmodd;
	}
	cout<<ans;
	return 0;
} 
