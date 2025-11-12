#include<bits/stdc++.h>
using namespace std;
int a[500005],b[500005];
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        b[i]=b[i-1]^a[i];
    }
    int l=1,gs=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j>=l;j--)
        {
            if((b[i]^b[j-1])==k)
            {
                gs++;
                l=i+1;
                break;
            }
        }
    }
    cout<<gs;
    return 0;
}
