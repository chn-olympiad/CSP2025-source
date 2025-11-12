#include<bits/stdc++.h>
using namespace std;
const int N=110;
typedef long long ll;
int n,m,r,a,id=1;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>a;
        if(i==1)
        {
            r=a;
        }
        else
        {
            if(a>r)
            {
                id++;
            }
        }
    }
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            id--;
            if(id==0)
            {
                if(i%2==1)
                {
                    cout<<i<<" "<<j;
                }
                else
                {
                    cout<<i<<" "<<n-j+1;
                }
            }
        }

    }
    return 0;
}
