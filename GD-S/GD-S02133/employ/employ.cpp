#include <bits/stdc++.h>
using namespace std;

const int maxn=505;
const int mod=998244353;
int n,m;
int s[maxn],c[maxn]; 

int f(int x)
{
	long long ans=1;
	for (int i=1;i<=x;i++)
	{
	    ans*=i;
	    ans%=mod;
	}
	return ans;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout); 
	cin>>n>>m;
    for (int i=1;i<=n;i++)
    {
    	cin>>s[i];
	}
    for (int i=1;i<=n;i++)
    {
    	cin>>c[i];
	}
	cout<<f(n)<<"\n";
}
