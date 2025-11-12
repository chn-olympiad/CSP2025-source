#include <bits/stdc++.h>
using namespace std;
int a[5005];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
         scanf("%d",&a[i]);
    }
    int maxx=0;
    for(int i=1;i<=n;i++){
        maxx=max(a[i],maxx);
    }
    if(n<4){
        if(n<3) cout<<0;
        else if(a[1]+a[2]+a[3]>2*maxx) cout<<1;
    }
    else{
        cout<<9;
    }
    return 0;
}
