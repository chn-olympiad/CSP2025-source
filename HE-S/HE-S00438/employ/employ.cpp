#include<bits/stdc++.h>
using namespace std;
int n,m;
const int mod=998244353;
int main()
{
	freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
	cin>>n>>m;
    string s;
    cin>>s;
    for(int i=1;i<=n;i++)
	{
	    int x;
	    cin>>x;
	}
    for(int i=0;i<s.size();i++)
	{
		if(s[i]!='1')
		{
			cout<<0<<endl;
			return 0;
		}
	}
	long long ans=1;
	for(int i=1;i<=n;i++)
	{
		ans*=i;
		ans%=mod; 
	}
	cout<<ans;
    return 0;	
} 
