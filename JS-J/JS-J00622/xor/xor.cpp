#include <bits/stdc++.h>
using namespace std;
int a[500005];
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin >> n >> k;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
    }
    int cnt=0,cur=a[1],ii=2;
    if(a[1]==k)
    {
        cnt++;
        cur=a[2];
        ii=3;
    }
    for(int i=ii;i<=n;i++)
    {
        cur^=a[i];
        if(cur==k)
        {
            cur=a[i+1];
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}
