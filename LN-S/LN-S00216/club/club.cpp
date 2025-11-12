#include<bits/stdc++.h>
using namespace std;
long long u,n,a1[100005],a2[100005],a3[100005],vis[100005];
bool cmp(long long aa,long long bb){
    return aa>bb;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%lld",&u);
    while(u--){
        bool flag1=0,flag2=0;
        long long ans=0;
        scanf("%lld",&n);
        for(long long i=1;i<=n;i++)
        {
            long long u1=0,u2=0,u3=0;
            scanf("%lld%lld%lld",&u1,&u2,&u3);
            a1[i]=u1,a2[i]=u2,a3[i]=u3;
            if(u2!=0 || u3!=0) flag1=1;
            if(u3!=0) flag2=1;
        }
        if(flag1==0){
            sort(a1+1,a1+1+n,cmp);
            for(long long i=1;i<=n/2;i++){
                ans+=a1[i];
            }
            printf("%lld\n",ans);
            continue;
        }
        else if(flag2==0){
            long long sh1=0,sh2=0;
            for(long long i=1;i<=n/2;i++)
            {
                long long maxn=a1[1],pos=1,ipos=1;
                for(long long j=2;j<=n;j++){
                    if(maxn<=a1[j]){
                        maxn=a1[j];
                        pos=j;
                        ipos=1;
                    }
                    if(maxn<=a2[j]){
                        maxn=a2[j];
                        pos=j;
                        ipos=2;
                    }
                }
                a2[pos]=0;a1[pos]=0;
                ans+=maxn;
                vis[pos]=1;
                if(ipos==1) sh1++;
                else if(ipos==2) sh2++;
            }
            for(long long i=1;i<=n;i++)
            {
                if(vis[i]==0)
                {
                    if(sh1>=n/2) ans+=a2[i];
                    else if(sh2>=n/2) ans+=a1[i];
                    else ans+=max(a1[i],a2[i]);
                }
            }
            printf("%lld\n",ans);
            for(long long i=1;i<=n;i++) vis[i]=0;
            continue;
        }
        else{
            long long sh1=0,sh2=0,sh3=0;
            for(long long i=1;i<=n;i++)
            {
                long long maxn=a1[1],pos=1,ipos=1;
                for(long long j=2;j<=n;j++){
                    if(maxn<=a1[j]){
                        if(sh1>=n/2) a1[j]=0;
                        else{
                            maxn=a1[j];
                            pos=j;
                            ipos=1;
                        }
                    }
                    if(maxn<=a2[j]){
                        if(sh2>=n/2) a2[j]=0;
                        else{
                            maxn=a2[j];
                            pos=j;
                            ipos=2;
                        }
                    }
                    if(maxn<=a3[j]){
                        if(sh3>=n/2) a3[j]=0;
                        else{
                            maxn=a3[j];
                            pos=j;
                            ipos=3;
                        }
                    }
                }
                a2[pos]=0;a1[pos]=0;a3[pos]=0;
                ans+=maxn;
                if(ipos==1) sh1++;
                else if(ipos==2) sh2++;
                else if(ipos==3) sh3++;
            }
            printf("%lld\n",ans);
        }
    }
   // qing kong kan i ding yi
    return 0;
}
