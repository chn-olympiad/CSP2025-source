#include<bits/stdc++.h>
using namespace std;
int n,k;
int cnt=0;

struct g{
    int fir,sec;
}ansone[500003];
bool sot(g a, g b)
{
    return a.fir<b.fir;
}
int a[500003];
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    int ber=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
        {
            int u=a[i];
            for(int k=i+1;k<=j;k++)
            {
                u^=a[k];
            }
            if(u==k)
            {
                ber++;
                ansone[ber].fir=i;
                ansone[ber].sec=j;
            }
        }
    }
    sort(ansone+1,ansone+1+ber,sot);
    for(int i=1;i<=ber;i++)
    {
        int ans=1;
        int s=ansone[i].sec;
        for(int j=i+1;j<=ber;j++)
        {
            if(ansone[j].fir>s)
            {
                s=ansone[j].sec;
                ans++;
            }
        }
        cnt=max(ans,cnt);
    }
    cout<<cnt;
    return 0;
}
