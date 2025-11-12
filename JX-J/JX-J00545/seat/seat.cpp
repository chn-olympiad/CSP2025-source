#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,b[105],x;
    cin>>n>>m;
    for(int i = 1;i<=n*m;i++)
    {
        cin>>b[i];
    }
    x=b[1];
    for(int i = 1;i<=n*m;i++)
    {
        for(int j = 2;j<=n*m;j++)
        {
            if(b[j]>b[j-1])
            {
                swap(b[j],b[j-1]);
            }
        }
    }
    for(int i = 1;i<=m;i++)
    {
        if(b[i]==x)
        {
            cout<<1<<" "<<i;
        }
    }
    return 0;
}
