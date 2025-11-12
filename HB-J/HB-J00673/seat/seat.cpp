#include<bits/stdc++.h>
using namespace std;
long long n,m,a[10005],x,y;
bool cmp(long long a,long long b)
{
    return a>b;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(long long i=1;i<=n*m;i++)
    {
        cin>>a[i];
    }
    x=1;
    y=1;
    for(long long i=2;i<=n*m;i++)
    {
        if(a[i]>a[1])
        {
            if(x%2==1)
            {
                if(y==m)
                {
                    x++;
                }
                else
                {
                    y++;
                }
            }
            else
            {
                if(y==1)
                {
                    x++;
                }
                else
                {
                    y--;
                }
            }
        }
    }
    cout<<x<<" "<<y<<endl;
    return 0;
}
