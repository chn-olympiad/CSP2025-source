#include<bits/stdc++.h>
    using namespace std;
    int a[110];
    bool cmp(const int &x,const int &y){
    return x>y;
    }
    int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
    cin>>a[i];
    }
    int p=a[1];
    sort(a+1,a+n*m+1,cmp);
    int h=1,l=1,d=1;
    if(p==a[1]){
    cout<<1<<" "<<1;
    return 0;
    }
    for(int i=2;i<=n*m;i++){
    if(d==1){
    if(h<n){
    h++;
    }
    else{
    l++;
    d=2;
    }
    }
    else if(d==2){
    if(h>1){
    h--;
    }
    else{
    l++;
    d=1;
    }
    }
    if(a[i]==p){
    cout<<l<<" "<<h;
    return 0;
    }
    }
    return 0;
    }
