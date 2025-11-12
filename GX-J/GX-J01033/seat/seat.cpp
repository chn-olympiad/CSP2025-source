#include<bits/stdc++.h>
using namespace std;
int ji(int a,int b)
{
    return a>b;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,a[105],l,w,b=1;
    cin>>n>>m;
    l=n*m;
    for(int i=1;i<=l;i++)
    {
        cin>>a[i];
    }
    w=a[1];
    sort(a+1,a+l+1,ji);
    for(int i=1;i<=n;i++)
    {
        if(i%2!=0)
        {
            for(int j=1;j<=m;j++)
            {
                if(a[b]==w)
                {
                    cout<<i<<" "<<j;
                    return 0;
                }
                b++;
            }
        }
        else
        {
            for(int j=m;j>=1;j--)
            {
                if(a[b]==w)
                {
                    cout<<i<<" "<<j;
                    return 0;
                }
                b++;
            }
        }
    }
    return 0;
}
