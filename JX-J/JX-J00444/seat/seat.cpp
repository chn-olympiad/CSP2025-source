#include<bits/stdc++.h>
using namespace std;
int main(){
   freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int c=n*m;
    int ar[c+1]={0};
    for(int i=1;i<c+1;i++){
        cin>>ar[i];
    }
    int su=ar[1];
    int max1=0,max2;
    int n1=1,m1=1;
    int zt=0;
    for(int j=1;j<=c;j++){
    for(int i=1;i<=c;i++){
        if(max1<ar[i]){
            max1=ar[i];
            max2=i;
        }
    }
        zt++;
       if(max1==su){
        break;
       }
        max1=0;
    ar[max2]=0;
    }
    if(zt%2==0)
    m1=zt/n;
    else{
        m1=zt/n+1;
    }
    n1=zt%n;
    if(m1%n==0){
        cout<<m1<<" "<<n1;
    }else{
        cout<<m1<<" "<<n;
    }
    return 0;
}
