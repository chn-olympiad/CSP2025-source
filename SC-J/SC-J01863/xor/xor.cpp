#include <bits/stdc++.h>
using namespace std;
bool flag=true;
int n,k,ans=0,ans1=0,ans2=0;
int a[500005];
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    if (k!=0)
    	flag=false;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
        if (a[i]!=1)
        	flag=false;
    }
    if (flag)
    {
    	cout<<n/2;
    	return 0;
	}
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n-i+1;j++)
        {
            if (i==1&&a[j]==k)
            {
                ans1++;
                j++;
                continue;
            }
            int tot=a[j]^a[j+1];
            for (int k=j+2;k<=j+i-1;k++)
                tot^=a[k];
            if (tot==k)
            {
                ans1++;
                j+=i;
            }
        }
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n-i+1;j++)
        {
            if (j==1&&a[i]==k)
            {
                ans2++;
                i++;
                continue;
            }
            int tot=a[j]^a[j+1];
            for (int k=i+2;k<=i+j-1;k++)
                tot^=a[k];
            if (tot==k)
            {
                ans2++;
                i+=j;
            }
        }
    cout<<max(ans1,ans2);
    return 0;
}