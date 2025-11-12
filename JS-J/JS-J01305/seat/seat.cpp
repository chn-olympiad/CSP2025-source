#include <bits/stdc++.h>
using namespace std;
int a[105];
bool cmp(int x,int y)
{
    return x>y;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i];
    }
    int x=a[1];
    sort(a+1,a+n*m+1,cmp);
    int xx;
    for(int i=1;i<=n*m;i++)
    {
        if(x==a[i])
        {
            xx=i;
            break;
        }
    }
    int a=xx/n,b=xx%n;
    if(b==0)
    {
        if(a%2==1)
        {
            cout<<a<<" "<<n;
        }
        else{
            cout<<a<<" "<<1;
        }
    }
    else{
        a++;
        if(a%2==1)
        {
            cout<<a<<" "<<b;
        }
        else{
            cout<<a<<" "<<n-b+1;
        }
    }
    return 0;
}
