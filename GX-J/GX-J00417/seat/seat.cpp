#include<bits/stdc++.h>
using namespace std;
bool px(long long a,long long b)
{
    return a>b;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    long long n,m,a[101],ming=0,shu=0;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i];
    }
    ming=a[1];
    sort(a+1,a+1+n*m,px);
    for(int i=1;i<=n*m;i++)
    {
        if(a[i]==ming)
        {
            shu=i;
            break;
        }
    }
    if(shu<n)
    {
        cout<<1<<" "<<shu;
    }
    else if(shu>=n)
    {
        if(shu/n%2!=0)
        {
            if(shu%n==0)
            {
                cout<<shu/n<<" "<<n;
            }
            else
            {
                cout<<shu/n+1<<" "<<n-shu%n+1;
            }
        }
        else if(shu/n%2==0)
        {
            if(shu%n==0)
            {
                cout<<shu/n<<" "<<1;
            }
            else
            {
                cout<<shu/n+1<<" "<<shu%n;
            }
        }
    }
    return 0;
}
