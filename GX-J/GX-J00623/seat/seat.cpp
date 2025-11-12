#include<bits/stdc++.h>
using namespace std;
long long n,m,a[10001],k=1;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n,m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i];
        if(a[i]>a[1])
        {
            k++;
        }
    }
    if(k%n==0)
    {
        cout<<k/n<<" "<<n;
        return 0;
    }
    else
    {
        cout<<k/n+2<<" "<<k%n+1;
    }

    return 0;
}


