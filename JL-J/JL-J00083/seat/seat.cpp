#include<bits/stdc++.h>
using namespace std;
int main(){
    //freopen("seat.in","r",stdin);
    //freopen("seat.out","w",stdout);
    int n,m,i,a,a1,a2,r1;
    cin>>n>>m;
    int c1[m*n];
    for(i=0;i<m*n;i++){
        scanf("%d",&c1[i]);
    }
    r1=c1[0];
    a2=1;
    for(i=0;i<n*m;i++){
        if(r1<c1[i])a2++;
    }
    int c=1,r=0,z=0;
    for(i=1;i<=a2;i++){
        if(z==0){
           r++;
            if(r>n){
                c++;
                z=1;
                r=n;
            }
        }else{
            r--;
            if(r<=0){
                c++;
                z=0;
                r=1;
            }
        }
    }
    cout<<c<<" "<<r;
    return 0;
}
