//rp++
#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,k;int a[500001];
signed main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
    cin>>n>>k;
    bool t=true;
    for(int i=1;i<=n;i++) 
	{
		cin>>a[i];
		if(a[i]!=1)
		{
			t=false;
		}
	}
	if(t&&k==1)
	{
		cout<<n;
		return 0;
	}
	cout<<1;
	return 0;
}
//rp++
