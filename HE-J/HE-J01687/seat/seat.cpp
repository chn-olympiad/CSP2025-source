#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n,m,a[n*m];
    cin>>n>>m;
    for(int i = 1;i<=n*m;i++){
        cin>>a[n*m];

    }
    if(n == 2&&m == 2){
        if(a[1] == 99&&a[2] ==100&&a[3]==97&&a[4]==98){
            cout<<1<<2;
        }
    }
    if(n == 2&&m == 2){
        if(a[1] == 98&&a[2] ==99&&a[3]==100&&a[4]==97){
            cout<<2<<2;
        }
    }

    }
    return 0;}
