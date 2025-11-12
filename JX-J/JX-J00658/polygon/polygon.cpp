#include <bits/stdc++.h>
using namespace std;
int main(){
    //freopen("polygon.in","r",stdin);
    //freopen("polygon.out","w",stdout);
    int n,tnt=0,b=0,maxn=0;
    scanf("%d",&n);
    int a[n+1];
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }for(int i=1;i<=n;i++){
        maxn=max(a[i],maxn);
    }
    for(int i=3;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int c=j;c<=i+j+1;c++){
                b+=a[c];
            }if(b>maxn*2)tnt++;
        }
    }cout<<tnt%998%244%353;
    return 0;
}
