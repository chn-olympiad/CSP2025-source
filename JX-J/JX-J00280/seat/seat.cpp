#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    long long h,l,m[101]={},n,s,d,ha,li;
    cin>>h>>l;
    n=h*l;
    for(int i=1;i<=n;i++){
        cin>>m[i];
    }
    s=m[1];
    for(int i=1;i<=n;i++){
        for(int j=1;j<n;j++){
            if(m[j]<m[j+1]){
                swap(m[j],m[j+1]);
            }

        }
    }
    for(int i=1;i<=n;i++){
        if(m[i]==s){
            d=i;
        }
    }
    if(d%h==0 and d/h%2==1){
        ha=h;
        li=d/h;
    }
    else if(d%h==0 and d/h%2==0){
        ha=1;
        li=d/h;
    }
    else if(d<h){
        ha=d;
        li=1;
    }
    else if(d/h%2==1){
        ha=h-d%h+1;
        li=d%h+1;
    }
    else if(d/h%2==0){
        ha=d%h;
        li=d/h+1;
    }
    cout<<li<<" "<<ha;
    return 0;
}
