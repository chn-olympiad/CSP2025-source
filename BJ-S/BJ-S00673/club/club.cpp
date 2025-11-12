#include<bits/stdc++.h>
using namespace std;
int t,n,ans,s1,s2,s3,f1,f2,f3;
struct node{
    int a1,a2,a3,s;
}a[114514];
bool cmp1(node x,node y){
    if(x.a2==x.a3&&y.a2==y.a3&&x.a2==y.a2&&y.a2==0) return x.a1>y.a1;
    if(x.a2==x.a3&&x.a2==0) return 1;
    if(y.a2==y.a3&&y.a2==0) return 0;
    return x.a1>y.a1;
}
bool cmp2(node x,node y){
    if(x.a1==x.a3&&y.a1==y.a3&&x.a1==y.a1&&y.a1==0) return x.a2>y.a2;
    if(x.a1==x.a3&&x.a1==0) return 1;
    if(y.a1==y.a3&&y.a1==0) return 0;
    return x.a2>y.a2;
}
bool cmp3(node x,node y){
    if(x.a2==x.a1&&y.a2==y.a1&&x.a2==y.a2&&y.a2==0) return x.a3>y.a3;
    if(x.a2==x.a1&&x.a2==0) return 1;
    if(y.a2==y.a1&&y.a2==0) return 0;
    return x.a3>y.a3;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);ans=s1=s2=s3=f1=f2=f3=0;
        for(int i=1;i<=n;i++){
            scanf("%d%d%d",&a[i].a1,&a[i].a2,&a[i].a3);a[i].s=0;
            if(a[i].a1!=0) f1=1;
            if(a[i].a2!=0) f2=1;
            if(a[i].a3!=0) f3=1;
        }
        if(!f2&&!f3&&f1){
            sort(a+1,a+n+1,cmp1);
            int i=1;
            while(s1<(n>>1))ans+=a[i++].a1,s1++;
            printf("%d\n",ans);
            continue;
        }
        if(f2&&!f3&&!f1){
            sort(a+1,a+n+1,cmp2);
            int i=1;
            while(s1<(n>>1)){
                ans+=a[i++].a2,s1++;
                //printf("%d ",a[i-1].a2);
            }
            printf("%d\n",ans);
            continue;
        }
        if(!f2&&f3&&!f1){
            sort(a+1,a+n+1,cmp3);
            int i=1;
            while(s1<(n>>1))ans+=a[i++].a3,s1++;
            printf("%d\n",ans);
            continue;
        }
        if(!f2&&f3&&!f1){
            sort(a+1,a+n+1,cmp3);
            int i=1;
            while(s1<=(n>>1))ans+=a[i++].a3,s1++;
            printf("%d\n",ans);
            continue;
        }
        else if(!f3&&f2&&f1){
            sort(a+1,a+n+1,cmp1);
            for(int i=1;i<=n;i++){
                if(a[i].a1>a[i].a2&&s1<=(n>>1))ans+=a[i].a1;
                else ans+=a[i].a2;
            }
            printf("%d\n",ans);
            continue;
        }
        else if(f3&&!f2&&f1){
            sort(a+1,a+n+1,cmp1);
            for(int i=1;i<=n;i++){
                if(a[i].a1>a[i].a3&&s1<=(n>>1))ans+=a[i].a1;
                else ans+=a[i].a3;
            }
            printf("%d\n",ans);
            continue;
        }
        else if(f3&&f2&&!f1){
            sort(a+1,a+n+1,cmp2);
            for(int i=1;i<=n;i++){
                if(a[i].a2>a[i].a3&&s1<=(n>>1))ans+=a[i].a2;
                else ans+=a[i].a3;
            }
            printf("%d\n",ans);
            continue;
        }
        sort(a+1,a+n+1,cmp1);
        for(int i=1;i<=n;i++){
            if(a[i].a1>max(a[i].a2,a[i].a3)&&s1<(n>>1)&&!a[i].s&&a[i].a1){
                ans+=a[i].a1;a[i].s=1;s1++;
            }
        }
        sort(a+1,a+n+1,cmp2);
        for(int i=1;i<=n;i++){
            if(a[i].a2>a[i].a3&&s2<(n>>1)&&!a[i].s&&a[i].a2){
                ans+=a[i].a2;a[i].s=1;s2++;
            }
        }
        sort(a+1,a+n+1,cmp3);
        for(int i=1;i<=n;i++){
            if(s3<(n>>1)&&!a[i].s&&a[i].a3){
                ans+=a[i].a3;a[i].s=1;s3++;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
