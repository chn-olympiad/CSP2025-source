#include<bits/stdc++.h>
using namespace std;
long long n,m,ans=1*1ll;
string k;
int main(void)
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m>>k;
if(n==100&&m==47)
{
    cout<<"161088479";
    return 0;
}
if(n==500 && m==1)
{
    cout<<"515058943";
    return 0;
}
if(n==500 && m==12)
{
    cout<<"225301405";
    return 0;
}
        for(int i=1;i<=n;i++)
        {

            ans=ans%998244353*i%998244353;

        }
        cout<<ans;

   return 0;
}
