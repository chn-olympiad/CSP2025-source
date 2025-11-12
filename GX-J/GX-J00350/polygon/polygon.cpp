#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n,l[5005],maxn=-1;
    long long sum;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>l[i];
        sum+=l[i];
        maxn=max(l[i],maxn);
    }
    if(n<3)
    {
         cout<<"0";
         return 0;
    }
    if(n==3&&sum>(2*maxn))
    {
        cout<<"1";
        return 0;
    }
    return 0;
}

