#include<bits/stdc++.h>//很显然的漏想情况了，我说第四题怎么能这么简单
using namespace std;
char pi[505];
int p[505];
int pa[505];
int day0[505];
int day1[505];
int ren[505];
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m;
    scanf("%d%d",&n,&m);
    scanf("%s",pi+1);
    for(int i=1;i<=n;i++)
        if(pi[i]=='1')
            p[i]=1;
    int head0=1,head1=1;
    for(int i=1;i<=n;i++)//第’头‘个0/1出现在哪天
    {
        if(p[i]==0)
            {day0[head0]=i;head0++;}
        else
            {day1[head1]=i;head1++;}
    }
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&pa[i]);
        pa[i]=day0[pa[i]];//记录他的耐心够撑到哪天
    }
    sort(pa,pa+n-1);
    //printf("%d",pa[3]);
    long long ans=1;
    for(int i=1;i<=m;i++)
    {
        ren[day1[i]]=n-*lower_bound(pa,pa+n-1,i)+1;
    }
    if(ren[day1[m]]==0)
        printf("0");
    else
    {
        for(int i=1;i<=m;i++)
        {
            ans=ans*(ren[day1[m-i+1]]-i+1);
            ans=ans%998244353;
        }
        for(int i=1;i<=n-m;i++)
        {
            ans*=i;
            ans=ans%998244353;
        }
    }
    printf("%lld",ans);
}
