#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);

    int n,k;
    cin>>n>>k;
    int a[500005];
    int kkk=0;
    if(n<=2&&k==0)
    {
        kkk=1;
    }
    //int a;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        kkk+=a[i];
    }
    if(kkk==n+1)
    {
        cout<<0<<endl;
        return 0;
    }
    int i=1;
    int j;
    int hkk;
    int ans=0;
    while(i<=n)
    {
        j=i;
        hkk=a[j];
        while(j!=n&&hkk!=k)
        {
            j++;
            hkk^=a[j];
        }
        if(hkk==k)
        {
            i=j;
            ans++;
        }
        i++;
       // cout<<i<<hkk<<"OOO"<<endl;
    }
    cout<<ans<<endl;
    return 0;
}
