#include<bits/stdc++.h>
using namespace std;
long long m[5005],n,ans;
void pol(int t,long long max_l,int sum,int s)
{
    if(s>=3)
    {
        if(sum>max_l*2)
            ans++;
    }
    for(int i=t+1;i<=n;i++)
    {
        pol(i,max(max_l,m[i]),sum+m[i],s+1);
    }
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin >>n;
    for(int i=1;i<=n;i++)
        cin >>m[i];
    pol(0,0,0,0);
    cout<<ans;
    return 0;
}
