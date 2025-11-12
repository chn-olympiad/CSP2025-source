#include<bits/stdc++.h>
using namespace std;
int n,m,a[20005],pm,ming;
bool cmp(int x,int y)
{

    return x>y;
}
int main(void)
{
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {

        cin>>a[i];
    }

    ming=a[1];

    sort(a+1,a+1+n*m,cmp);

    for(int i=1;i<=n*m;i++)
    {
        if(a[i]==ming)
        {
            pm=i;
            break;
        }
    }
    if(pm%n==0)
    cout<<pm/n;
    else cout<<pm/n+1;
    cout<<" ";
    if(pm%(2*n)>n)cout<<n-pm%n+1;
    else
    {
        if(pm%n==0)cout<<n;
        else cout<<pm%(2*n);
    }
}
