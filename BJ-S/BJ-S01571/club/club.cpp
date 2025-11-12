#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int T,n,a[100005][4],ans,t[100005],ca,cb,cc;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%d",&T);
    while(T--){
        ans=0;
        scanf("%d",&n);
        ca=cb=cc=0;
        for(int i=1;i<=n;i++){
            scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
            if(a[i][1]>a[i][2]){
                if(a[i][1]>a[i][3]) t[i]=1,ca++,ans+=a[i][1];
                else t[i]=3,cc++,ans+=a[i][3];
            }else{
                if(a[i][2]>a[i][3]) t[i]=2,cb++,ans+=a[i][2];
                else t[i]=3,cc++,ans+=a[i][3];
            }
        }
        while(ca>(n>>1)){
            int x=1e9,c=0,d=0;
            for(int i=1;i<=n;i++){
                if(t[i]==1){
                    int b=a[i][1]-max(a[i][2],a[i][3]);
                    if(b<x){
                        x=b;
                        if(a[i][2]>a[i][3]) d=2;
                        else d=3;
                        c=i;
                    }
                }
            }
            t[c]=d;
            ans-=x;
            ca--;
        }
        while(cb>(n>>1)){
            int x=1e9,c=0,d=0;
            for(int i=1;i<=n;i++){
                if(t[i]==2){
                    int b=a[i][2]-max(a[i][1],a[i][3]);
                    if(b<x){
                        x=b;
                        if(a[i][1]>a[i][3]) d=1;
                        else d=3;
                        c=i;
                    }
                }
            }
            t[c]=d;
            ans-=x;
            cb--;
        }
        while(cc>(n>>1)){
            int x=1e9,c=0,d=0;
            for(int i=1;i<=n;i++){
                if(t[i]==3){
                    int b=a[i][3]-max(a[i][2],a[i][1]);
                    if(b<x){
                        x=b;
                        if(a[i][1]>a[i][2]) d=1;
                        else d=2;
                        c=i;
                    }
                }
            }
            t[c]=d;
            ans-=x;
            cc--;
        }
        printf("%d\n",ans);
    }
    return 0;
}
