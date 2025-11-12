#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,l[110];
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>l[i];
    }
    int zy=0,pd=l[1];
    for(int i=1;i<n*m;i++){
        for(int g=i;g<n*m;g++){
            int zc=0;
            if(l[g]<l[g+1]){
                zc=l[g+1];
                l[g+1]=l[g];
                l[g]=zc;
                if(l[g+1]==pd){
                  zy=g+1;
                }
            }
        }
    }
    int h,hl;
    if(zy%n==0){
        if(zy/n%2==0){
            h=1;
        }
        if(zy/n%2!=0){
            h=n;
        }
    }
    else{
        h=zy%n;
        if((zy/n+1)%2==0){
            h=n-h+1;
        }
    }

    if(zy%n==0){
        hl=zy/n;
    }
    else{
        hl=zy/n+1;
    }

    cout<<hl<<" "<<h;
    return 0;
}
