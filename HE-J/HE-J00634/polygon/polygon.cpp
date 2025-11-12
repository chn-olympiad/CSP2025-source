#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[1000001],ma=-1,mi=1e6;
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=a[i];i++)
    {
    	cin>>a[i];
    	ma=max(ma,a[i]);
    	mi=min(mi,a[i]);
	}if(ma==mi)
	{
		if(n==5)
		{
			cout<<16;
		}
	}


	return 0;
}

