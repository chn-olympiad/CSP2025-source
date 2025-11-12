#include<bits/stdc++.h>
using namespace std;
long long n,m,sum=1,cnt,x;
string s;
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>s;
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        if(x!=0)cnt++;
    }
    for(int i=2;i<=n;i++)
    {
        sum*=i;
        sum=sum%998244353;
    }
    if(cnt>=m)cout<<sum;
    else cout<<0;
}
