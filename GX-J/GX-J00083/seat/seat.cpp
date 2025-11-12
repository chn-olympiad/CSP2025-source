#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int h,l;
    cin>>h>>l;
    long long fs[h*l+4];
    for(int i=0;i<h*l;i++){
        cin>>fs[i];
    }
    int r=fs[0],zs=0;
    for(int i=1;i<h*l;i++){
        if(fs[i]>r){
            zs+=1;
        }
    }
    int szl=zs/h+1,szh;;
    if((zs/h)%2==0){
        zs=zs-(zs/h)*h;
        szh=zs+1;
    }else{
        zs=zs-(zs/h)*h;
        szh=h-zs;
    }
    cout<<szl<<" "<<szh;
    return 0;
}
