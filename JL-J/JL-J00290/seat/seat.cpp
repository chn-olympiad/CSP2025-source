#include<bits/stdc++.h>
using namespace std;
int s[10010];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>s[i];
    }
    int c=s[1];
    sort(s+1,s+1+n*m);
    int ans;
    for(int i=1;i<=n*m;i++)
    {
        if(s[i]==c)
        {
            ans=n*m-i+1;
            break;
        }
    }
    //cout<<ans<<endl;
    int r;
    c=(ans-1)/m+1;
    if(ans%m==0)
    {
        r=m;
    }
    else
    {
        r=ans%m;
    }
    if(c%2==0)
    {
        r=m-r+1;
    }
    cout<<c<<' '<<r;
    return 0;
}
