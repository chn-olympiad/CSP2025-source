#include<bits/stdc++.h>
using namespace std;
long long n,m[1e+5],ans=0,t1,t2;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>m[i];
	for(int i=3;i<=n;i++)
	{
		t1=1,t2=1;
		for(int j=1;j<=n;j++)t1=(t1*j)%998244353;
		for(int j=n;j>n-i;j--)t2=(t2*j)%998244353;
		ans+=t2/t1;	
    }
    cout<<ans;	                                   
} 
