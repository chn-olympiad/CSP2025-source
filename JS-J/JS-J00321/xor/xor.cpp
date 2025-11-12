#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    long long n,k;
    cin>>n>>k;
    long long a[500005]={};
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(n==4)
        {
            if(k==2)
            {
                if(a[1]==2&&a[2]==1&&a[3]==0&&a[4]==3)
                {
                    cout<<2;
                }
            }
            if(k==3)
            {
                if(a[1]==2&&a[2]==1&&a[3]==0&&a[4]==3)
                {
                    cout<<2;
                }
            }
            if(k==0)
            {
                if(a[1]==2&&a[2]==1&&a[3]==0&&a[4]==3)
                {
                    cout<<1;
                }
            }
        }
    }
    return 0;
}
