#include <bits/stdc++.h>
using namespace std;
const int N=2e6+10;
int a[4][N],l[4];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int n,T;
    scanf("%d",&T);
    while(T--){
        long long ans=0,t,m;
        bool f=1;
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d%d%d",&a[0][i],&a[1][i],&a[2][i]);
            if(a[1][i]!=0 || a[2][i]!=0) f=0;
        }
        if(f){
            sort(a[0]+1,a[0]+n+1,greater<int>());
            for(int i=1;i<=n/2;i++) ans+=a[0][i];
            printf("%d\n",ans);
            continue;
        }
        long long nn=pow(3,n);
        for(int i=1;i<=nn;i++){
            l[1]=l[2]=l[0]=t=0;m=i;
            for(int j=1;j<=n;j++){
                if(l[m%3]>=n/2) break;
                l[m%3]++;
                t+=a[m%3][j];
                m/=3;
            }
            ans=max(ans,t);
        }
        printf("%d\n",ans);
    }
    return 0;
}
