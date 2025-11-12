#include<bits/stdc++.h>
using namespace std;
map<int,long long> t;
long long i,j,n,m,a[1000005],he[1000005],cnt;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>m>>a[1];
    he[1]=a[1];
    if(a[1]==m)
    {
        cnt++;
    }
    for(i=2;i<=n;i++)
    {
        cin>>a[i];
        he[i]=he[i-1]^a[i];
        for(j=2;j<=i;j++)
        {
            if(he[i]^he[j-1]==m)
            {
                cnt++;
            }
        }
    }
    cout<<cnt-2;
    return 0;
}

