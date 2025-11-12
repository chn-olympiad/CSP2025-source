#include<bits/stdc++.h>
using namespace std;
const int mx=5E5+10;
int n,k,i,a[mx],l,r;
bool b=0;
int ans=0;
int xo(int l,int r)
{
    int i,x;
    if(l==0&&r==0) return 0;
    else if(l==r&&l!=0)
        return l;
    else
    {
       for(i=l;i<r;i++)
        {
            x=a[l];
            x=a[i+1]^x;
        }
        return x;
    }
}
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(i=1;i<=n;i++) cin>>a[i];
    for(l=1;l<=n;l++)
    {
        for(r=l;r<=n;r++)
        {
            if(xo(l,r)==k)
            {
                ans++;
                l=r+1;
            }
            else
            r++;
        }
    }
    cout<<ans+1;
    return 0;
}
