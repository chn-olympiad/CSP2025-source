#include<bits/stdc++.h>
using namespace std;
int n,m,c=1,r=1,R;
int a[100];
int max[100];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    R=a[1];
    max[0]=R;
    for(int j=1;j<=n*m;j++){
        for(int i=1;i<=n*m;i++){
            if(a[i]>max[i]){
               max[j]=a[i];
               a[i]=a[i]-a[i];
        }
        max++;
    }
    
    for(int q;q<=n*m;q++){
        if(r%2==1)
           if(max[q]>R){
              r=r+1;
        }
        if(r%2==0)
           if(max[q]>R){
              r=r-1;
        }
        if(r>n){
            c=c+1;
            r=1;
        }
        if(r<=0){
            c=c+1;
            r=1;
        }
    }
    cout<<c<<r;
    return 0;
}
}
