#include<bits/stdc++.h>

using namespace std;

int n,a[5001],ans=0;

bool can(int l,int r){
    int sum=0,max1=0;
    for(int i=l;i<=r;i++){
        sum+=a[i];
        if(a[i]>max1){
            max1=a[i];
        }
    }
    if(sum>(max1*2)){
        return true;
    }
    else{
        return false;
    }
}

int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(can(i,j)){
                ans++;
            }
        }
    }
    printf("%d",ans%998%244%353);
    return 0;
}
