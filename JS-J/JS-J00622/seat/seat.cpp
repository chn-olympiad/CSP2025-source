#include <bits/stdc++.h>
using namespace std;
int a[105];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin >> n >> m;
    for(int i=1;i<=n*m;i++)
    {
        cin >> a[i];
    }
    int R=a[1],pos=-1;
    sort(a+1,a+n*m+1,greater<int>());
    for(int i=1;i<=n*m;i++)
    {
        if(a[i]==R)
        {
            pos=i;
        }
    }
    if(pos%n!=0)
    {
        cout<<pos/n+1<<" ";
    }
    else
    {
        cout<<pos/n<<" ";
    }
    if(((pos-1)/n)%2==0)
    {
        if(pos%n!=0)
        {
            cout<<pos%n;
        }
        else
        {
            cout<<n;
        }
    }
    else
    {
        if(pos%n==0)cout<<1;
        else cout<<n+1-pos%n;
    }
    return 0;
}
