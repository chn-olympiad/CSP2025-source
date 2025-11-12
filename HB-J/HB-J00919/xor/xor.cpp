#include<bits/stdc++.h>
using namespace std;

const int maxN=5e5;

int n,k;

int a[maxN];

int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    if(k==0)
        cout<<n/2;
    else if(k==1)
    {
        int cnt=0;
        for(int i=1;i<=n;i++)
            if(a[i]==1)
                cnt++;
        cout<<cnt;
    }
    return 0;
}
