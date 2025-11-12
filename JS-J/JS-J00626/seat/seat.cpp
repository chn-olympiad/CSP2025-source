#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],num,ans;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i];
    }
    num=a[1];
    sort(a+1,a+n*m+1);
    for(int i=1;i<=n*m;i++)
    {
        if(num==a[i])
        {
            ans=i;
            break;
        }
    }
    ans=n*m-ans+1;
    int sum=ceil(ans*1.0/n);
    //cout<<num<<" "<<ans<<" "<<sum<<" ";
    if(sum%2==1)
    {
        cout<<ceil(ans*1.0/n)<<" "<<ans-((ceil(ans*1.0/n)-1)*n);
    }
    else
    {
        cout<<ceil(ans*1.0/n)<<" "<<n-(ans-((ceil(ans*1.0/n)-1)*n))+1;
    }
    return 0;
}
