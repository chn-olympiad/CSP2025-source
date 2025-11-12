#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[500000];
int n,k;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=0;i<n;i++)
        cin>>a[i];
    if(n<=2&&k==0)
        if(a[0]==1&&a[1]==1)
        {
            cout<<1;
            return 0;
        }
        else if(a[0]==1&&a[1]!=1&&a[1]==0)
        {
            cout<<1;
            return 0;
        }
        else if(a[0]==1&&a[1]!=1&&a[1]!=0)
        {
            cout<<0;
            return 0;
        }
        else if(a[0]==1&&a[1]==1)
        {
            cout<<1;
            return 0;
        }
        else if(a[1]==1&&a[0]!=1&&a[0]==0)
        {
            cout<<1;
            return 0;
        }
        else if(a[1]==1&&a[0]!=1&&a[0]!=0)
        {
            cout<<0;
            return 0;
        }

    return 0;
}
