#include<bits/stdc++.h>
using namespace std;
long long n,m,r;
long long a[1001];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i];
        if(i==1)r=a[1];
    }
    for(int i=1;i<=n*m;i++)
    {
        for(int j=1;j<=n*m-i;j++)
        {
            if(a[j]<a[j+1])swap(a[j],a[j+1]);
        }
    }
    for(int i=1;i<=n*m;i++)
    {
        if(a[i]==r)
        {
            if(i%n!=0)
            {
                if((i/n+1)%2==1)cout<<(i/n)+1<<" "<<i%n;
                else cout<<(i/n)+1<<" "<<n-(i%n)+1;
            }
            else
            {
                if((i/n)%2==1)cout<<i/n<<" "<<n;
                else cout<<i/n<<" "<<1;
            }
        }
    }
    return 0;
}
