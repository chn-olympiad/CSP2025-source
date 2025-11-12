#include<bits/stdc++.h>
using namespace std;
typedef long long lld;
typedef double llf;
//-----------------------------
lld mod=998244353;

int n,m;
bool flag=1;
string t;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>t;
	for(int i=0;i<n;++i)
	{
		
		if(t[i]!='1')
		{
			flag=0;
			break;
		}
	}
	if(!flag)
	{
		cout<<0;
		return 0;
	}
	else
	{
		lld sum=1;
		for(int i=1;i<=n;++i)
		{
			sum*=i;
			sum%=mod;
		}
		cout<<(sum%mod);
	}
	//LQH保佑我~zr保佑我~
	fclose(stdin);
	fclose(stdout);
	return 0;
 }

