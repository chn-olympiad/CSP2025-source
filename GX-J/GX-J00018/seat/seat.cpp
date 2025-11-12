#include<bits/stdc++.h>
using namespace std;
int sum[150];
int a,t=1;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>sum[i];
    }
    a=sum[1];
    sort(sum+1,sum+n*m+1);
    for(int i=1;i<=n*m;i++)
    {
        if(sum[i]==a)
        {
            t=n*m-i+1;
        }
    }
    cout<<t<<endl;
    if(t%n>0)
    {
        if(t%n!=0)
        {
            cout<<t/n+1<<" "<<t%n;
        }
        else
        {
            cout<<t/n<<" "<<m;
        }
    }
    else
    {
        if(t%n!=0)
        {
            cout<<t/n+1<<" "<<m-t%n+1;
        }
        else
        {
            cout<<t/n<<" "<<m;
        }
    }
    return 0;
}

