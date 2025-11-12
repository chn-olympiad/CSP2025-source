#include<bits/stdc++.h>
using namespace std;
#define Int long long
#define el '\n'
const int mod=998244353;
Int read()
{
    Int s=1,d=0;
    char chat=getchar();
    while(chat<'0'||chat>'9')
    {
        if(chat=='-') s=-1;
        chat=getchar();
    }
    while(chat>='0'&&chat<='9')
    {
        d=d*10+chat-'0';
        chat=getchar();
    }
    return s*d;
}
Int n,stick[5005],sum[5005],cnt=0;
int sums(int k,int pos)
{
    int ans=1;
    for(int i=pos;i<=n;i++)
    {
        if(stick[i]<=k) ans+=sums(k-stick[i],i+1);
        else break;
    }
    return ans;
}
int main()
{
    //polygon
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    n=read();
    for(int i=1;i<=n;++i) stick[i]=read();
    stable_sort(stick+1,stick+n+1);
    for(int i=1;i<=n;++i) sum[i]=sum[i-1]+stick[i];
    for(int i=3;i<=n;++i)
    {
        int posr=upper_bound(sum+1,sum+n+1,stick[i]*2+1)-sum;
        if(posr>i) continue;
        Int date=sum[posr]-(stick[i]*2+1);
        cnt=(cnt+sums(date,1))%mod;
    }
    cout<<cnt<<el;
    return 0;
}
