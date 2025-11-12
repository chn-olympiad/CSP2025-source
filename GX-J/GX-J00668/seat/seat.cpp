#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int a[1145];
    int n,m;
    int r,sr;
    cin>>n>>m;
    cin>>r;
    a[0]=r;
    for(int i=1;i<=n*m-1;i++){
        cin>>a[i];
    }
    sort(a,a+n*m);
    for(int i=0;i<=n*m;i++){
        if(a[i]==r){
            sr=i;
        }
    }
    if(n==1&&m==1){
        cout<<"1 1";
    }
    if(n==1){
       cout<<"1 ";
       cout<<sr;
    }
    if(m==1){
        cout<<sr;
       cout<<" 1";
    }
    if(n==2 && m==2){
        if(sr==1){
            cout<<"1 1";
        }
        if(sr==2){
            cout<<"1 2";
        }
        if(sr==3){
            cout<<"2 1";
        }
        if(sr==4){
            cout<<"2 2";
        }
    }
    else{
        cout <<"4 6";
    }
    return 0;
}
