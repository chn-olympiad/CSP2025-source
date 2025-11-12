#include<bits/stdc++.h>
using namespace std;
long long t,n,a[100100][6];
long long b1,b2,b3;
long long c[100100];int l=0;
long long ans=1>>30;
inline void dfs(int i,long long v){
    if(i==n+1){
        c[++l]=v;
        return;
    }
        if(b1<n/2){
                b1++;
            dfs(i+1,v+a[i][1]);
        b1--;
        }
        if(b2<n/2){
                b2++;
            dfs(i+1,v+a[i][2]);
        b2--;
        }
        if(b3<n/2){
                b3++;
            dfs(i+1,v+a[i][3]);
        b3--;
        }
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%lld",&t);
    for(;t--;){
        scanf("%lld",&n);
        for(int i=1;i<=n;i++){
            scanf("%lld",&a[i][1]);
            scanf("%lld",&a[i][2]);
            scanf("%lld",&a[i][3]);
        }
        b1=0,b2=0,b3=0;l=0;ans=1>>30;
        dfs(1,0);
        for(int i=1;i<=l;i++){
            ans=max(ans,c[i]);
        }
        printf("%d\n",ans);
    }
    return 0;
}
