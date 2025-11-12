#include<bits/stdc++.h>
using namespace std;
long long n,k;
int t;
int book[500010][3],dp[500010];
string a[500010];
string totwo(int x)
{
    string s="";
    if(x==0) return "0";
    while(x!=0)
    {
        char c=x%2+'0';
        s=s+c;
        x/=2;
    }
    return s;
}
string yihuo(string s1,string s2)
{
    string s="";
    if(s1.size()>s2.size())
       swap(s1,s2);
    int len1=s1.size(),len2=s2.size();
    for(int i=0;i<len2;i++)
    {
        if(i<len1)
        {
            if(s1[i]!=s2[i])
                s+='1';
            else
                s+='0';
        }
        else s+=s2[i];
    }
    return s;
}
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    scanf("%lld%lld",&n,&k);
    string ans=totwo(k);
    int x;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&x);
        a[i]=totwo(x);
    }
    for(int i=1;i<=n;i++)
    {
        if(a[i]==ans)
        {
            t++;
            book[t][1]=book[t][2]=i;
        }
        string s=a[i];
        for(int j=i+1;j<=n;j++)
        {
            s=yihuo(s,a[j]);
            if(s==ans)
            {
                book[++t][1]=i;
                book[t][2]=j;
            }
        }
    }
    dp[1]=1;
    for(int i=2;i<=t;i++)
    {
        dp[i]=1;
        for(int j=1;j<i;j++)
        {
            if(book[j][2]<book[i][1])
                dp[i]=max(dp[i],dp[j]+1);
        }
    }
    printf("%d\n",dp[t]);
    return 0;
}
