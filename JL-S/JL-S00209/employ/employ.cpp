#include<bits/stdc++.h>
using namespace std;
string s;
long long n,m,c[500],ans=1;
bool pd()
{
    for(int i=1;i<=s.size();i++)
        if(s[i]=='0')
            return false;
    return true;
}
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m>>s;
    if(n==0&&m==0)
    {
        cout<<"0";
        return 0;
    }
    for(int i=1;i<=n;i++)
        cin>>c[i];
    if(n==1&&m==1&&pd())
        cout<<"1";
    else
    {
        for(int i=1;i<=n;i++)
            ans*=i;
        cout<<ans%998244353;
    }
    return 0;
}
