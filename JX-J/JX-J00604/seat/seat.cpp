#include <bits/stdc++.h>
using namespace std;
#define ll long long//xianleizaihang
int n,m,id,temp;
int a[1008];
int c,r;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    temp=a[1];
    sort(a+1,a+1+n*m);
    for(int i=n*m;i>=1;i--){
        if(a[i]==temp){
            id=n*m-i+1;
            break;
        }
    }
    //cout<<id<<endl;
    if(id<=n){
        c=1;
        r=id;
    }
    else if(id>n){
        c=id/n+1;
        if(c%2==1){
            r=id-(c-1)*n;
        }
        else if(c%2==0){
            r=n-(id-(c-1)*n)+1;
        }
    }
    cout<<c<<" "<<r;
    return 0;
}
