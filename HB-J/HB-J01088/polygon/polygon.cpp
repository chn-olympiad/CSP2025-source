#include<bits/stdc++.h>
using namespace std;
const int N=5e3+5,mod=998244353;
long long ans=0;
int n,a[N],st[N],gs[N],vis[N],td[N],len,top=0;
void f(int dq,int he,int wz)
{
    if(len-dq>n-wz)
        return;
    if(st[top]==n&&dq!=len)
        return;
    if(dq==len)
    {
        
        sort(st+1,st+len+1);
        if(st[1]==0)
            return;
        if(st[len]*2<he)
        {
            printf("%d\n",len);
            for(int i=1;i<=dq;i++)
                printf("%d ",st[i]);
            printf("\n\n");
            ans=(ans+1)%mod;
        }
        return;
    }
    int flag=0;
    for(int i=wz+1;i<=n;i++)
    {
        if(!vis[i])
        {
            flag=1;
            vis[i]=1;st[++top]=a[i];
            f(dq+1,he+a[i],i);
            st[top]=0;top--;
            f(dq+1,he,i);
            vis[i]=0;
        }
    }
    if(flag==0)
        return;
}
int  main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=3;i<=n;i++)
    {
        len=i;
        f(0,0,0);
    }
    printf("%lld",ans);
    return 0;
}