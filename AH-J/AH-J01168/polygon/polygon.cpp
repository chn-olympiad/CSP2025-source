#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n,a[111],z=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(int j=1;j<=n;j++){
        for(int x=j+1;x<=n;x++){
            for(int y=x+1;y<=n;y++){
                int b=0;
                if(a[j]>b) b=a[j];
                if(a[x]>b) b=a[x];
                if(a[y]>b) b=a[y];
                if(a[j]+a[x]+a[y]>2*b) z++;
            }
        }
    }
    printf("%d",z);
    return 0;
}
