#include<bits/stdc++.h>
using namespace std;
int n,m,c,r,num,ans,a[111];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n*m;i++){
        scanf("%d",&a[i]);
    }
    num=a[1];
    sort(a+1,a+n*m+1);
    for(int i=n*m;i>=1;i--){
        if(num==a[i]){
            ans=n*m-i+1;
            break;
        }
    }
    if(ans%n==0){
        c=ans/n;
    }
    else{
        c=ans/n+1;
    }
    if(c%2==1){
        r=ans-n*(c-1);
    }
    else{
        r=n*2-ans+1;
    }
    cout<<c<<" "<<r;
    return 0;
}
