#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","r",stdout);
    int t,n;
    int a[n+1];
    scanf("%d",&t);
    int ma=INT_MIN,ma2=INT_MIN,ma3=INT_MIN;
    int c1=0,c2=0,c3=0,k=n/2,s=0,s1=0,s2=0;
    if(n==1){
        c1=1;
    }
    else if(n==2){
            c1==1;
        c2==1;
    }
    else if(n>=3){
            c3=n/3;
        if(n%3>=1){
            c1=n/3+(n%3)/2;
            c2=n/3+(n%3)/2;
        }
    }
    while(t--){
            cin>>n;
        for(int i=1;i<=n;i++){
               cin>>a[i];
        }
  if(c1<=k){
        for(int i=1;i<=n;i++){
            if(ma<a[i]){
                ma=a[i];
            }
        }
        s+=ma;
    }
    if(c2<=k){
        for(int i=1;i<=n;i++){
            if(ma2<a[i]){
                ma2=a[i];
            }
        }

    }
    if(c3<=k){
        for(int i=1;i<=n;i++){
            if(ma3<a[i]){
                ma3=a[i];
            }
        }

    }
        }
    printf("%d\n%d\n%d",ma,ma2,ma3);
    return 0;
}
