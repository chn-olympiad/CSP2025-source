#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    long long n,a[100000],q[100000],w[100000],e[100000],s=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        for(int j=1;j<=a[i];j++)
        {
            cin>>q[j]>>w[j]>>e[j];
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=a[i];j++)
        {
            if(q[j]>=w[j]&&q[j]>=e[j])
            {
                s+=q[j];
                break;
                if(w[j]>=q[j]&&w[j]>=e[j])
                {
                    s+=w[j];
                    break;
                    if(e[j]>=w[j]&&e[j]>=q[j])
                    {
                        s+=e[j];
                    }
                }
            }
        }
    }
    cout<<s;
    return 0;
}