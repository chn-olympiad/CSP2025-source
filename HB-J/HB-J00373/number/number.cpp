#include<bits/stdc++.h>
using namespace std;
long long a[10000005],b,c=1;
int cf(int x,int y){
    int z;
    for(int i=1;i<y;i++){
        x=x*x;
    }
    return x;
}
int cs(int x,int y){
    if(x>y){
        return 10*x+y;
    }
    if(y>x){
        return 10*y+x;
    }
}
int cc(int x,int y){
    if(x>y){
        return y,x;
    }
    if(y>x){
        return x,y;
    }
}
int ca(int x,int y){
    if(x>y){
        return y,x;
    }
    if(y<x){
        return x,y;
    }
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>a[10000005];

    for(long long i=1;i<=1000005;i++){
        b==cc(a[i],a[i+1])*10+ca(a[i],a[i+1]);
    }
    cout<<b;
return 0;
}
