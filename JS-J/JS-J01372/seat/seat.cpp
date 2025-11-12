#include<bits/stdc++.h>
using namespace std;
int m,n,s,mc;
int a[105];
int main(){
ios::sync_with_stdio(0);
cin.tie(0);cout.tie(0);
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n*m;i++){
        cin>>a[i];
    }
    s=a[0];
    sort(a,a+n*m);
    for(int i=0;i<n*m;i++){
        if(a[i]==s){
            mc=i;
            break;
        }
    }
    //cout<<mc<<"\n";
    mc=n*m-mc;
    int x=ceil(mc*1.0/m);
    cout<<x<<" ";
    mc-=m*(x-1);
    if(x%2==0){
    cout<<m-mc+1;
    }else{
    cout<<mc;
    }
    return 0;
}
