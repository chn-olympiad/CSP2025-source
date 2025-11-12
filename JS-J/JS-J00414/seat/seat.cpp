#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y)
{
    return x>y;
}
void lesson1()
{
    int n,m;
    cin>>n>>m;
    int a[n*m+10],z;
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i];
    }
    z=a[1];
    sort(a+1,a+1+n*m,cmp);
    int k;
    for(int i=1;i<=n*m;i++)
    {
        if(a[i]==z)
        {
            k=i;
            break;
        }
    }
    if(k%n==0)
    {
        cout<<k/n<<" ";
    }
    else
    {
        cout<<k/n+1<<" ";
    }
    k%=(2*n);
    if(k<=n)
    {
        cout<<k;
    }
    else
    {
        cout<<2*n+1-k;
    }
}
int main()
{
    freopen(seat.in,"r",stdin);
    freopen(seat.out,"w",stdout);
    lesson1();
    return 0;
}
