#include <bits/stdc++.h>
#define rep(i,s,t) for(int i=s;i<=t;++i)
using namespace std;
const int N=1e5+11;
int T,n,vis[N];
struct ps{
    int val,num;
}a[N],b[N],c[N];
struct person{
    int x,y,z,num;
}p[N];
bool cmp(ps x,ps y){
    return x.val>y.val;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        int flag1=1,flag2=1;
        rep(i,1,n){
            scanf("%d%d%d",&a[i].val,&b[i].val,&c[i].val);
            p[i]={a[i].val,b[i].val,c[i].val,i};
            a[i].num=b[i].num=c[i].num=i;
            if(c[i].val!=0)flag1=flag2=0;
            else if(b[i].val!=0)flag1=0;
        }
        if(flag1==1){
            sort(a+1,a+1+n,cmp);
            int ans=0;
            rep(i,1,n/2)ans+=a[i].val;
            printf("%d\n",ans);
            continue;
        }
        else if(flag2==1){
            sort(a+1,a+1+n,cmp);
            sort(b+1,b+1+n,cmp);
            int ans=0;
            rep(i,1,n){
                if(p[i].x>p[i].y){
                    int flag=0;
                    rep(j,1,n/2){
                        if(a[j].val==p[i].x&&a[j].num==p[i].num){
                            ans+=a[j].val;
                            flag=1;
                            break;
                        }
                    }
                    if(flag==0)ans+=p[i].y;
                }
                else if(p[i].x<=p[i].y){
                    int flag=0;
                    rep(j,1,n/2){
                        if(b[j].val==p[i].x&&b[j].num==p[i].num){
                            ans+=b[j].val;
                            flag=1;
                            break;
                        }
                    }
                    if(flag==0)ans+=p[i].y;
                }
            }
            printf("%d\n",ans);
            continue;
        }
    }
    return 0;
}
