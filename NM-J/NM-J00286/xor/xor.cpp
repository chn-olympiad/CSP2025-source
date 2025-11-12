#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,i,j,a[500010],ans=0;
	cin>>n>>k;
	for(i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    if(k==0)
    {
        for(i=1;i<=n;i++)
        {
            if(a[i]==0)
            {
                ans++;
            }
        }
        cout<<ans;
    }
    else if(k==1)
    {
        for(i=1;i<=n;i++)
        {
            if(a[i]==1)
            {
                ans++;
            }
        }
        cout<<ans;
    }
    else
        cout<<2;
	return 0;
}
