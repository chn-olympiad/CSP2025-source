#include<bits/stdc++.h>
using namespace std;
long long cj[101];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    long rc,rm,ans=0;
    for(long long i=1;i<=n*m;i++)
    {
        cin>>cj[i];
    }
    rc=cj[1];
    sort(cj+1,cj+1+n*m);
    for(long long i=1;i<=n*m;i++)
    {
        if(rc==cj[i])
        {
            rm=n*m-i+1;
            break;
        }
    }
    for(int i=1;i<=m;i++)
    {
        for(int l=1;l<=n;l++)
        {
            ans++;
            if(ans==rm)
            {
                if(i%2==0)
                {
                    cout<<i<<" "<<n-l+1;
                    return 0;
                }
                else
                {
                    cout<<i<<" "<<l;
                    return 0;
                }
            }
        }
    }
    return 0;
}
