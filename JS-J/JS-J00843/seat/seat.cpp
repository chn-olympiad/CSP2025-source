#include<bits/stdc++.h>
using namespace std;
long long n,m,a[105],k;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
        cin>>a[i];
    int k=a[1],b;
    sort(a+1,a+m*n+1);
    for(int i=n*m;i>=1;i--)
    {
        if(k==a[i])
        {
            b=n*m-i;
            break;
        }
    }
    int h=1,l=1;
    for(int i=1;i<=b;i++)
    {
        if(l%2==1)
        {
            if(h!=n) h++;
            else l++;
        }
        else
        {
            if(h!=1) h--;
            else l++;
        }
    }
    cout<<l<<" "<<h;
    return 0;


}
