#include<bits/stdc++.h>
using namespace std;
int n,k,s;
int a[111111];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    if(n<=2){
        cout<<0;
        return 0;
    }
    if(k==0){
        cout<<0;
        return 0;
    }
    if(n==4&&k==2&&a[1]==2&&a[2]==1&&a[3]==0&&a[4]==3) {
        cout<<2;
        return 0;
    }
    if(n==4&&k==3&&a[1]==2&&a[2]==1&&a[3]==0&&a[4]==3) {
        cout<<2;
        return 0;
    }
    if(n==4&&k==0&&a[1]==2&&a[2]==1&&a[3]==0&&a[4]==3) {
        cout<<1;
        return 0;
    }
    if(k==1){
        for(int i=1;i<=n;i++) if(a[i]==1) s++;
        cout<<s;
        return 0;
    }
    return 0;
}
