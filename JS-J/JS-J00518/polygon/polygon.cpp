#include<bits/stdc++.h>
using namespace std;
const int N=998244353;
int a[5005];
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n,maxai=-1;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        maxai=max(a[i],maxai);
    }
    if(n==3)
    {
            if(a[1]+a[2]+a[3]>2*maxai)
            {
                cout<<1;
            }
            else
            {
                cout<<0;
            }
            return 0;
    }
    else if(maxai==1)
        {
            int k=1;
            for(int i=1;i<=n;i++)
            {
                k=k*2;
                k=k%N;
            }
            k=k+N;
            k=k-n;
            k=k-n*(n-1)/2;        k=k%N;
            cout<<k-1;
        return 0;
    }
}
