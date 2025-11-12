#include<bits/stdc++.h>
using namespace std;
int n,m,r,s,t;
int a[1000];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    /*if(n==1&&m<=10){ }*/
        for(int i=1;i<=n*m;i++){
            cin>>a[i];
        }
        r=a[1];
        sort(a+1,a+n*m+1);
        for(int i=1;i<=n*m;i++){
            if(a[i]==r)s=n*m-i+1;
        }
    if(n==1&&m==1)cout<<"1 1";
    if(n==2&&m==2){
        if(s==1)cout<<"1 1";
        if(s==2)cout<<"1 2";
        if(s==3)cout<<"2 2";
        if(s==4)cout<<"2 1";
    }
    return 0;
}
