#include<bits/stdc++.h>
using namespace std;

long long a[500009],ek[22];

int xori(int x,int y){
    int xy=0;
    int xa[22]={0},ya[22]={0},xya[22]={0};
    int xi=0,yi=0;
    while(x){
        xi++;
        xa[xi]=x%2;
        x/=2;
    }
    while(y){
        yi++;
        ya[yi]=y%2;
        y/=2;
    }
    int xyi=max(xi,yi);
    while(xyi){
        if(xa[xyi]+ya[xyi]==1){
            xya[xyi]=1;
            xy+=ek[xyi];
        }
        xyi--;
    }
    return xy;
}

int ixor(int x,int y){
    int you=y,cha=y-x+1,ti=a[y];
    while(cha){
        ti=xori(a[y],a[y-1]);
        y--;
        cha--;
    }
    return ti;
}

int main(){
    long long n,l,r,k;
    cin>>n>>k;
    bool pyo[]
    ek[0]=0;
    ek[1]=1;
    for(int i=2;i<=22;i++){
        ek[i]=ek[i-1]*2;
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    return 0;
}
