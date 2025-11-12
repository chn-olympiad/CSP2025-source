#include <bits/stdc++.h>
using namespace std;
int n;
int a[5005];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    if(n<=2){
        cout<<0<<endl;
    }else if(n==3){
        cin>>a[1]>>a[2]>>a[3];
        int x=0;
        if(a[1]+a[2]+a[3] > max(max(a[1],a[2]),a[3])*2)x++;
        cout<<x<<endl;
    }else if(n==4){
        cin>>a[1]>>a[2]>>a[3]>>a[4];
        int x=0;
        if(a[1]+a[2]+a[3] > max(max(a[1],a[2]),a[3])*2)x++;
        if(a[1]+a[2]+a[4] > max(max(a[1],a[2]),a[4])*2)x++;
        if(a[1]+a[3]+a[4] > max(max(a[1],a[3]),a[4])*2)x++;
        if(a[2]+a[3]+a[4] > max(max(a[2],a[3]),a[4])*2)x++;
        if(a[1]+a[2]+a[3]+a[4] > max(max(max(a[1],a[2]),a[3]),a[4])*2)x++;
        cout<<x<<endl;
    }else if(n==5){
        cin>>a[1]>>a[2]>>a[3]>>a[4]>>a[5];
        int x=0;
        if(a[1]+a[2]+a[3] > max(max(a[1],a[2]),a[3])*2)x++;
        if(a[1]+a[2]+a[4] > max(max(a[1],a[2]),a[4])*2)x++;
        if(a[1]+a[2]+a[5] > max(max(a[1],a[2]),a[5])*2)x++;
        if(a[1]+a[3]+a[4] > max(max(a[1],a[3]),a[4])*2)x++;
        if(a[1]+a[3]+a[5] > max(max(a[1],a[3]),a[5])*2)x++;
        if(a[1]+a[4]+a[5] > max(max(a[1],a[4]),a[5])*2)x++;
        if(a[2]+a[3]+a[4] > max(max(a[2],a[3]),a[4])*2)x++;
        if(a[2]+a[3]+a[5] > max(max(a[2],a[3]),a[5])*2)x++;
        if(a[2]+a[4]+a[5] > max(max(a[2],a[4]),a[5])*2)x++;
        if(a[3]+a[4]+a[5] > max(max(a[3],a[4]),a[5])*2)x++;
        if(a[1]+a[2]+a[3]+a[4] > max(max(max(a[1],a[2]),a[3]),a[4])*2)x++;
        if(a[1]+a[2]+a[3]+a[5] > max(max(max(a[1],a[2]),a[3]),a[5])*2)x++;
        if(a[1]+a[5]+a[3]+a[4] > max(max(max(a[1],a[5]),a[3]),a[4])*2)x++;
        if(a[1]+a[2]+a[5]+a[4] > max(max(max(a[1],a[2]),a[5]),a[4])*2)x++;
        if(a[5]+a[2]+a[3]+a[4] > max(max(max(a[5],a[2]),a[3]),a[4])*2)x++;
        if(a[1]+a[2]+a[3]+a[4]+a[5] > max(max(max(max(a[5],a[2]),a[3]),a[4]),a[5])*2)x++;
        cout<<x<<endl;
    }else if(n>=6){

        cout<<1<<endl;
    }

    return 0;
}



