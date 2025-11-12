#include<bits/stdc++.h>
using namespace std;

int a[11][11]={0},b[100];

void p(int s){
    bool d=false,p;
    while(d==true){
        p=true;
        for(int i=0;i<s;i++){
            if(b[i]<b[i+1]){
                swap(b[i],b[i+1]);
                p=false;
            }
    }
    d=p;
    }
}

void fun(int x,int y,int s,int n){
    int fx[5]={0,0,0,-1,1};
    int fy[5]={0,-1,1,0,0};
    for(int i=1;i<=5;i++){
        int nx=x+fx[i];
        int ny=x+fy[i];
        if(nx>0 && nx<=x && ny>0 && ny<=y && a[nx][ny]==0){
            if(b[s]==n){
                cout<<x<<" "<<y;
                break;
            }else{
                a[nx][ny]=b[s];
                fun(nx,ny,s+1,n);
            }
        }
    }
}

int main(){
    int x,y,n;
    cin>>x>>y;

    for(int i=0;i<x*y;i++){
        cin>>b[i];
    }p(x*y);
    n=b[0];
    if(x==1 &&y==1){
        cout<<1<<1;
        return 0;
    }
    else{
        fun(1,1,0,n);
    }
    return 0;
}
