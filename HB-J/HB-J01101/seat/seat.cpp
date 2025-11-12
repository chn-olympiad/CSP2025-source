#include<bits/stdc++.h>
using namespace std;
long long m,n;
long long q[1000];
long long q1,sum,sum1;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>m>>n;
    for(int i=1;i<=m*n;i++)
    {
        cin>>q[i];
    }
    q1=q[1];
    while(1)
    {
        sum=0;
        for(int i=1;i<=m*n;i++)
        {
            if(q[i]<q[i+1])
            {
                swap(q[i],q[i+1]);
                sum++;
            }
        }
        if(sum==0)
            break;
    }
    for(int i=1;i<=m*n;i++)
    {
        if(q[i]==q1)
        {
            sum1=i;
        }
    }
    /*
    if(sum1<=n)
    {
        cout<<1<<' '<<sum1;
    }
    else if((sum1/n)%2==0)
    {
        cout<<sum1/n+1<<' '<<sum1%n+1;
    }
    else if((sum1/n)%2!=0)
    {
        cout<<sum1/n+1<<' '<<n-(sum1%n)+1;//what the fuck!what's +1?fuck!!!!
    }//fuck NOI at all
    */
    if(sum1<=n)
    {
        cout<<1<<' '<<sum1;
    }
    else if(sum1%n==0)
    {
        if((sum1/n)%2==0)
        {
            cout<<sum1/n<<' '<<n-(sum1%n)+1;
        }
        else{
            cout<<sum1/n<<' '<<sum1%n+1;
        }
    }
    else
    {
        if((sum1/n)%2==0)
        {
            cout<<sum1/n+1<<' '<<n-(sum1%n);
        }
        else{
            cout<<sum1/n+1<<' '<<sum1%n+1;
        }
    return 0;//fuck ccf BMF*2
}
}
