#include<bits/stdc++.h>
using namespace std;
int n,a[5010],ans;
vector<int> jihe;
void dfs(int st,int len,int nowlen)
{
    if(nowlen==len)
    {
        int s=0,maxn=0;
        for(int i=0;i<jihe.size();i++) s+=jihe[i],maxn=max(jihe[i],maxn);
        if(s>maxn*2) ans++,ans%=998244353;
        return;
    }
    if(st==n+1) return;
    jihe.push_back(a[st]);
    dfs(st+1,len,nowlen+1);
    jihe.pop_back();
    dfs(st+1,len,nowlen);

}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    if(*max_element(a+1,a+n+1)==1 && n>20)
    {
        int sum=1;
        for(int i=1;i<=n;i++) sum*=2,sum%=998244353;
        sum-=(n+((n-1)*n/2))+1;
        printf("%d",sum%998244353);
        return 0;
    }
    for(int i=3;i<=n;i++) dfs(1,i,0);
    printf("%d",ans);

    return 0;
}
