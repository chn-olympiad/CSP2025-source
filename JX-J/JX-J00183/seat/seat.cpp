#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int m,n,a,a1,p=1,m1,n1;
    cin>>n>>m;
    cin>>a1;
    for(int i=1;i<m*n;i++)
    {
        cin>>a;
        if(a>a1)
        {
            p++;
        }
    }
    m1=p/n;
    if(m1*n!=p)
    {
        m1++;
    }
    n1=p%(2*n);
    if(n1>n)
    {
        n1-=n;
    }
    cout<<n1<<" "<<m1;
    return 0;

}
