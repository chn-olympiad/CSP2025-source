#include <bits/stdc++.h>
using namespace std;

long long n,m,a[101]={};

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(long long i=1;i<=n*m;i++)
    {
        cin>>a[i];
    }
    long long num=a[1];
    sort(a+1,a+1+n*m);
    int k;
    for(long long i=n*m,j=1;i>=1,j<=n*m;i--,j++)
    {
        if(a[i]==num)
        {
            k=j;
            break;
        }
    }
    if((k/n+1)%2==1)
    {
        if(k%n==0)
        {
            cout<<k/n<<" "<<1;
        }
        else
        {
            cout<<k/n+1<<" "<<k%n;
        }
    }
    if((k/n+1)%2==0)
    {
        if(k%n==0)
        {
            cout<<k/n<<" "<<n;
        }
        else
        {
            cout<<k/n+1<<" "<<n+1-k%n;
        }
    }
    return 0;
}
