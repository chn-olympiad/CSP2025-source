#include <bits/stdc++.h>
using namespace std;
int n,a[1000000],k,ans,sum;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
       cin>>a[i];
    for(int i=1;i<=n;i++)
    {
		if(a[i]==k)
		{
			ans++;
			i++;
		}
		sum+=a[i];
		if(k!=0)
			if(sum%k==0&&sum!=0)
		    {
			    ans++;
			    sum=0;
		    }
		
    }
    cout<<ans;
    return 0;
}
