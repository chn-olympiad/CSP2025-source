#include<bits/stdc++.h>
using namespace std;
int n,a[5010],h[5010],ans;
int solve(int x,int y){
    int ma=a[x];
    for(int i=x+1;i<=y;i++)
        ma=max(ma,a[i]);
    return ma;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        h[i]=h[i-1]+a[i];
    }
    if(n==3)
        if(a[1]+a[2]+a[3]>2*max(a[1],max(a[2],a[3])))
            printf("1");
        else
            printf("0");
    for(int k=1;k<n;k++){
        for(int i=1;i<=n-2;i++){
            for(int j=i+2;j<=n;j++){
                if((h[j]-h[i-1])>2*(solve(i,j)))
                    ans++,ans%=998244353;
            }
        }
        memset(h,0,sizeof(h));
        for(int i=0;i<n;i++){
            swap(a[i],a[i+1]);
        }
        swap(a[0],a[n]);
        for(int i=1;i<=n;i++)
            h[i]=h[i-1]+a[i];
    }
    printf("%d",ans);
    return 0;
}
