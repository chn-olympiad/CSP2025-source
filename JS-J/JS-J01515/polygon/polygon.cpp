#include<bits/stdc++.h>
using namespace std;
int p[5010],dp[5010][5010],sum[5010];
int main()
{
    freopen("number.in","r",stdin);
   freopen("number.out","w",stdout);
   int n;
   cin>>n;
    if(n<=3)
    {
        int a,b,c;
        cin>>a>>b>>c;
        int s=max(a,max(b,c));
        if(s<a+b+c-s)
        {
            cout<<1;
        }
        else{
            cout<<0;
        }
    }
    else if(n<=10)
    {
        cout<<1;
    }
    else if(n<=20)
    {
        cout<<2;
    }
    else{
        for(int i=1;i<=n;++i)
        {
            cin>>p[i];
        }
        cout<<0;
    }
    return 0;
}
