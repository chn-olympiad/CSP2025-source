#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,num;
int a[110];
signed main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i];
    }
    int f=a[1];
    sort(a+1,a+1+n*m);
    for(int i=n*m;i>=1;i--)
    {
        if(a[i]==f)
        {
            num=n*m-i+1;
        }
    }
    int s=num/n;
    int t=num%n;
    if(t==0)
    {
        if(s%2==0)
        {
            cout<<s<<" "<<"1";
        }
        else
        {
        cout<<s<<" "<<n;
        }
    }

    else if((s+1)%2==0)
    {
        cout<<s+1<<" "<<n-(num%n)+1;
    }
    else
    {
        cout<<s+1<<" "<<num%n;
    }

    return 0;
}

