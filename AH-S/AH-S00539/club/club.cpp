#include<bits/stdc++.h>
using namespace std;
long long T,n,a[100005],b[100005],c[100005],ch[1000005],t[100005],f[100005],t1,t2,t3,sum;
int main(void){
    //freopen("club.in","r",stdin);
    //freopen("club.out","w",stdout);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%lld",&T);
    while(T--){
        t1=t2=t3=sum=0;
        scanf("%lld",&n);
        for(long long i=1;i<=n;i++){
            scanf("%lld%lld%lld",&a[i],&b[i],&c[i]);
            ch[i]=max(a[i],max(b[i],c[i]))-(a[i]+b[i]+c[i]-max(a[i],max(b[i],c[i]))-min(a[i],min(b[i],c[i])));
            if(a[i]>=b[i]){
                if(a[i]>=c[i])t[i]=1,t1++,sum+=a[i];
                else t[i]=3,t3++,sum+=c[i];
            }else{
                if(b[i]>=c[i])t[i]=2,t2++,sum+=b[i];
                else t[i]=3,t3++,sum+=c[i];
            }
        }
        if(max(max(t1,t2),t3)>n/2){
            if(t1>t2){
                if(t1>t3){
                    long long te=t1-n/2,cnt=0;
                    for(long long i=1;i<=n;i++)
                        if(t[i]==1)
                            f[++cnt]=ch[i];
                    sort(f+1,f+cnt+1);
                    for(long long i=1;i<=te;i++)
                        sum-=f[i];
                }else{
                    long long te=t3-n/2,cnt=0;
                    for(long long i=1;i<=n;i++)
                        if(t[i]==3)
                            f[++cnt]=ch[i];
                    sort(f+1,f+cnt+1);
                    for(long long i=1;i<=te;i++)
                        sum-=f[i];
                }
            }else{
                if(t2>t3){
                    long long te=t2-n/2,cnt=0;
                    for(long long i=1;i<=n;i++)
                        if(t[i]==2)
                            f[++cnt]=ch[i];
                    sort(f+1,f+cnt+1);
                    for(long long i=1;i<=te;i++)
                        sum-=f[i];
                }else{
                    long long te=t3-n/2,cnt=0;
                    for(long long i=1;i<=n;i++)
                        if(t[i]==3)
                            f[++cnt]=ch[i];
                    sort(f+1,f+cnt+1);
                    for(long long i=1;i<=te;i++)
                        sum-=f[i];
                }
            }
        }
        printf("%lld\n",sum);
    }
    return 0;
}
/*
AFO ji4
Luogu uid:1057768
*/
