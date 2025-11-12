#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+5;
struct node{
    int cnt;
    int v[4];
}b[N];
int a[N][4],n,us1,us2,us3,ans,k,res,cyd;
bool cmp(node x,node y){
    return x.v[k]>y.v[k];
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    scanf("%d",&T);
    while(T--){
        ans=0;
        scanf("%d",&n);
        for(int i=1;i<=n;++i){
            scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
            b[i].cnt=i;
            b[i].v[1]=a[i][1]-max(a[i][2],a[i][3]);
            b[i].v[2]=a[i][2]-max(a[i][1],a[i][3]);
            b[i].v[3]=a[i][3]-max(a[i][2],a[i][1]);
        }
        us1=us2=us3=0;
        for(int i=1;i<=n;++i){
            if(a[i][1]>a[i][2]&&a[i][1]>a[i][3]){
                us1++;
            }else if(a[i][2]>a[i][1]&&a[i][2]>a[i][3]){
                us2++;
            }else if(a[i][3]>a[i][2]&&a[i][3]>a[i][1]){
                us3++;
            }
        }
        if(us1<=n/2&&us2<=n/2&&us3<=n/2){
            for(int i=1;i<=n;++i){
                ans+=max(a[i][1],max(a[i][2],a[i][3]));

            }
            printf("%d\n",ans);
            continue;
        }
        for(k=1;k<=3;++k){
            res=0;
            sort(b+1,b+n+1,cmp);
            for(int i=1;i<=n/2;++i){
                res+=a[b[i].cnt][k];
            }
            for(int i=n/2+1;i<=n;++i){
                cyd=0;
                for(int j=1;j<=3;++j){
                    if(j==k) continue;
                    cyd=max(cyd,a[b[i].cnt][j]);
                }
                res+=cyd;
            }
            ans=max(ans,res);
        }
        printf("%d\n",ans);
    }
    return 0;
}
