#include<bits/stdc++.h>
using namespace std;
int n,m,a[110];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    int wz=0;
    for(int i=0;i<m*n;i++)
        cin>>a[i];
    if(n==1&&m==1)
    {
        cout<<1<<" "<<1;
        return 0;
    }
    int r=a[0];
    sort(a,a+(n*m),greater<int>());
    for(int i=0;i<n*m;i++)
        if(r==a[i])
        {
            wz=i+1;
            break;
        }
    if(wz%n==0)
    {
        cout<<wz/n<<" ";
        if((wz/n)%2==0)
        {
            cout<<1;
        }
        else
        {
            cout<<n;
        }
    }
    else
    {
        cout<<(wz/n)+1<<" ";
        if(((wz/n)+1)%2!=0&&wz%n==1)
        {
            cout<<1;
        }
        else
        {
            cout<<(n-(wz%n))+1;
        }
    }
    return 0;
}
