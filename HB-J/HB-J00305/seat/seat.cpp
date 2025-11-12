#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[101];
int cnt;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    int k=n*m;
    for(int i=1;i<=k;i++)
    {
        cin>>a[i];
    }
    int tmp=a[1];
    sort(a+1,a+k+1);
    for(int i=k;i>=1;i--)
    {
        if(a[i]==tmp)
        {
            cnt=k-i+1;
        }
    }
    int ans=cnt/n+1;
    int sum=cnt%n;
    if(sum==0)
    {
        if(ans%2==0)
        {
            cout<<ans-1<<" "<<n;
        }
        else
        {
            cout<<ans-1<<" "<<1;
        }

    }
    else
    {
        if(ans%2==0)
        {
            cout<<ans<<" "<<n-sum+1;
        }
        else
        {
            cout<<ans<<" "<<sum;
        }
    }
    return 0;
}
