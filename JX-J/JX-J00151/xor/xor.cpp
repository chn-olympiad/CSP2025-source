#include <bits/stdc++.h>
using namespace std;
int e(int a)
{
    int a1=a,ss=0,l=0;
    while(a1!=0)
    {
        l++;
        if(a1%2==0)
        {
            ss+=0;
        }
        else{
            ss+=pow(10,l-1);
        }
        a1/=2;
    }
    return ss;
}
int x(bool a,bool b)
{
    return a^b;
}
int xs(int a,int b)
{
    int l=max(a,b),ss=0;
    int l1=0;
    while(l!=0)
    {
        l1++;
        l/=10;
    }
    for(int i=1;i<=l1;i++)
    {
        ss+=x(a%10,b%10)*pow(10,i-1);
        a/=10;b/=10;
    }
    return ss;
}
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k,s[100001]= {0},dp[100001]= {0};
    cin>>n>>k;
    int kk=e(k);
    for(int i=1; i<=n; i++)
    {
        cin>>s[i];
        dp[i]=xs(e(s[i]),dp[i-1]);
    }
    dp[1]=s[1];
    for(int i=2; i<=n; i++)
    {
        dp[i]=xs(e(s[i]),dp[i-1]);
    }
    int ans=1;
    for(int i=1; i<=n; i++)
    {
        for(int j=i;j<=n;j++)
        {
            if(xs(dp[j],dp[i])==kk) ans=max(j-i,ans);
        }
    }
    cout<<ans;
    return 0;
}
