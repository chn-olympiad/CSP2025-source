#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seaf.out","w",stdin);
    int a[10005],b,m,n;
    cin>>m>>n;
    b=m*n;
    for(int i=1;i<=b;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+b+1);
    for(int i=b;i>=1;i--)
    {
        for(int j=i;j>=m;j--)
        {
            for(int l=i;l>=n;l--)
            {
                if(a[i]==a[1])
                {
                    cout<<j<<l;
                }

            }
        }
    }
    return 0;
}
