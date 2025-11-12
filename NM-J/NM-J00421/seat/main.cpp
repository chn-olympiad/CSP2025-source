#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n=0,m=0;
    cin>>n>>m;
    int shushu[n*m+5];
    for(int i=0;i<n*m;i++){
        cin>>shushu[i];
    }
    int chenji=0;
    chenji=shushu[0];
    int weizhi=0;
    sort(shushu+0,shushu+n*m);
    reverse(shushu+0,shushu+n*m);
    for(int i=0;i<n*m;i++){
            cout<<i;
        if(shushu[i]==chenji){
            weizhi=i+1;
        }
    }
    int c=0,r=0;
    cout<<c<<" "<<r;
    if(weizhi%n==0){
        c=int(weizhi/n);
    }
    else{
        c=int(weizhi/n)+1;
    }
        if(c%2==0){
        r=weizhi-(c-1)*n;
        r=n-r;
    }
    else{
        r=weizhi-(c-1)*n;
    }
    cout<<c<<" "<<r;
    return 0;
}
