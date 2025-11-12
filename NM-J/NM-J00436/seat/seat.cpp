#include"bits/stdc++.h"
using namespace std;
int a[110];
int cnt=1;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    int p;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i];
        p=a[1];
    }
    sort(a+1,a+1+n*m);
    if(n==1&&m==1)
    {
        cout<<1<<" "<<1;
    }
    else if(n==1)
    {
        for(int i=1;i<=m;i++)
        {
            if(a[i]>p)
            {
                cnt++;
            }

        }
        cout<<1<<" "<<cnt;
    }
    else if(m==1)
    {
        for(int i=1;i<=n;i++)
        {
            if(a[i]>p)
            {
                cnt++;
            }

        }
        cout<<cnt<<" "<<1;
    }
    return 0;

}
