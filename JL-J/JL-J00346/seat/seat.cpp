#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10;
struct node{
    int sz,bh;
}a[N];
int n,m,cd,wz,h,l;
bool cmp(node x,node y){
    return x.sz>y.sz;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    cd=n*m;
    for(int i=1;i<=cd;i++){
        cin>>a[i].sz;
        a[i].bh=i;
    }
    sort(a+1,a+cd+1,cmp);
    for(int i=1;i<=cd;i++){
        if(a[i].bh==1){
            wz=i;
            break;
        }
    }
    if(wz%n!=0){
        l=(wz/n)+1;
    }
    if(wz%n==0){
        l=wz/n;
    }
    if(l%2!=0&&wz%n!=0){
        h=wz%n;
    }
    if(l%2!=0&&wz%n==0){
        h=n;
    }
    if(l%2==0&&wz%n==0){
        h=1;
    }
    if(l%2==0&&wz%n!=0){
        h=n-(wz%n)+1;
    }
    cout<<l<<" "<<h;
    return 0;
}
