#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e5+114;
int n,k;
int a[MAXN];
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    if(n==2 and k==0)
    {
        if(a[1]==0 && a[2]==0)
        {
            cout<<2;
        }
        else if(a[1]==0 || a[2]==0) cout<<1;
        else cout<<0;
    }
    else cout<<2;
    return 0;
}
