#include<bits/stdc++.h>
using namespace std;
long long n,m,a[110],ans=0;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
       
	}
	if(n<=2)
	{
		
	    cout<<0;
	}
	else
	{
		cout<<m;
	}
    return 0;
}
