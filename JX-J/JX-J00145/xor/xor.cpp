#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],sum;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        if(a[i]==1)
        {
            sum++;
        }
    }
    if(m==1)
    {
        cout<<sum;
    }
    return 0;
}
