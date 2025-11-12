#include<bits/stdc++.h>
using namespace std;
int n,k,a[500010];
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i = 1;i<=n;i++) cin>>a[i];
    int l=-1,c_l=1;
    for(int i = 1;i<n;i+=c_l)
    {
        int x = a[i];
        c_l=1;
        for(int j = i+1;j<=n;j++)
        {
            x = x^a[j];
            if(a[j]==k) break;
            if(x == k)
            {
                c_l = j-i;
                l = max(l,c_l);
            }
        }
    }
    if(l==-1) l=1;
    cout<<l;
    return 0;
}
