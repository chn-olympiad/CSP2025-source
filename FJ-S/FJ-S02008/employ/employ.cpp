#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int mod=998244353;
char s[550];
int a[550];
int main()
{
	//only 5  
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n;
	scanf("%d%s",&n,s);
	int f=1;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(s[i]=='0')
		{
			f=0;
		}
	}
	if(!f)
	{
		cout<<"0"<<endl;
	}
	else
	{
		ll m=1ll*n;
		ll ret=1;
		for(ll i=1;i<=m;i++)
		{
			ret*=i;
			ret%=mod;
		}
		cout<<ret<<endl;
	}
	int q_q=0;
	return q_q; 
} 
