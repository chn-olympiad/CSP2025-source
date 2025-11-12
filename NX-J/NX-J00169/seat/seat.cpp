#include<bits/stdc++.h>
using namespace std;
int a[10000005];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,pm;
    cin>>n>>m;
    int d=n*m;
    for(int i=0;i<d;i++)
    {
        cin>>a[i];
    }
    int t=a[0];
    sort(a,a+d);
    int s=0;
    for(int i=d-1;i>=0;i--)
    {
        s++;
        if(a[i]==t)
        {
            pm=s;
            break;
        }
    }
    if(pm%n==0)
    {
        if((pm/m)%2==1)
        cout<<pm/m<<" "<<n;
        else
        cout<<pm/m<<" "<<1;

    }
    else{
        if(((pm/m)+1)%2==1)
        cout<<(pm/m)+1<<" "<<pm%n;
        else
        cout<<(pm/m)+1<<" "<<n-pm%n+1;
    }
    return 0;
}
