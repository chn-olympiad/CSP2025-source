#include<bits/stdc++.h>
using namespace std;
int a[5010];
int n;
int cnt;
bool b[5010];
void pac()
{
    memset(b,false,sizeof(b));
    for(int i=1;i<=pow(2,n);i++)
    {
        int j;
        for(j=n;j>0;j--)
        {
            if(b[j])    b[j]=false;
            else    break;
        }
        b[j]++;
        int cn=0;
        int sum=0,mx=-1;
        for(int j=1;j<=n;j++)    if(b[j])    cn++,sum+=(b[j]?a[j]:0),mx=max((b[j]?a[j]:-1),mx);
        if(cn<3)    continue;
        if(sum>2*mx)    cnt=(cnt+1)%998244353;
    }
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)    cin>>a[i];
    pac();
    cout<<cnt;
    return 0;
}
