#include<bits/stdc++.h>
using namespace std;

int n,sum,ans;
int a[10000];

int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    if(n==3){
        for(int i=1;i<=n-2;i++){
            for(int j=2;j<=n-1;j++){
                for(int k=3;k<=n;k++){
                    sum=max(a[i],max(a[j],a[k]));
                    if(a[i]+a[j]+a[k]>sum*2){
                        ans++;
                    }
                }
            }
        }
    }else if(n==4){
        for(int i=1;i<=n-3;i++){
            for(int j=2;j<=n-2;j++){
                for(int k=3;k<=n-1;k++){
                    for(int q=4;q<=n;q++){
                        sum=max(max(a[i],a[q]),max(a[j],a[k]));
                        if(a[i]+a[j]+a[k]+a[q]>sum*2){
                            ans++;
                        }
                    }
                }
            }
        }
    }else if(n==5){
        for(int i=1;i<=n-4;i++){
            for(int j=2;j<=n-3;j++){
                for(int k=3;k<=n-2;k++){
                    for(int q=4;q<=n-1;q++){
                        for(int w=5;w<=n;w++){
                            sum=max(max(max(a[i],a[q]),max(a[j],a[k])),a[w]);
                            if(a[i]+a[j]+a[k]+a[q]+a[w]>sum*2){
                                ans++;
                            }
                        }
                    }
                }
            }
        }
    }
    printf("%d\n",sum%998244353);
    return 0;
}
