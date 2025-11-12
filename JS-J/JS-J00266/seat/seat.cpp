#include<bits/stdc++.h>
using namespace std;
long long n,m,a[100005],x,ans;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i];
    }
    x=a[1];
    sort(a+1,a+1+n*m,greater<int>());
    for(int i=1;i<=n*m;i++)
    {
        if(a[i]==x)
        {
            ans=i;
            break;
        }
    }   
    cout<<(ans+n-1)/n<<" ";
    if(((ans+n-1)/n)%2==1)
    {
        if(ans%n==0)
            cout<<n;
        else
            cout<<ans%n;    
    }
    else
    {
        if(ans%n==0)
            cout<<1;
        else
        {
            cout<<n-(ans%n)+1;
        }    
    }
    return 0;
}