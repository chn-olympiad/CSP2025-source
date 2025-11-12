#include<bits/stdc++.h>
using namespace std;
int t,n,sum[4],ans,flag;
struct ch{
    int v,from;
    ch(){}
    ch(int x,int y){
        v=x;
        from=y;
    }
}a[100001];
struct dd{
    int v,i;
    dd(int x){
        i=x;
    }
};
bool cmp(ch x,ch y){
    return x.v<y.v;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        ans=flag=0;
        memset(sum,0,sizeof(sum));
        for(int i=1;i<=n;i++){
            dd x(1),y(2),z(3);
            scanf("%d%d%d",&x.v,&y.v,&z.v);
            if(x.v<y.v)
                swap(x,y);
            if(y.v<z.v)
                swap(y,z);
            if(x.v<y.v)
                swap(x,y);
            a[i]=ch(x.v-y.v,x.i);
            sum[x.i]++;
            ans+=x.v;
        }
        for(int i=1;i<=3;i++)
            if(sum[i]>n/2)
                flag=i;
        if(flag){
            sort(a+1,a+n+1,cmp);
            for(int i=1;sum[flag]>n/2;i++){
                if(a[i].from==flag){
                    ans-=a[i].v;
                    sum[flag]--;
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
