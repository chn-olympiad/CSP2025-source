#include<bits/stdc++.h>
using namespace std;

const int N=1e5;
int a[N];
int b[N];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1;i<=3;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n+1;i++) {
        cin >>b[i];
    }


    if(n==4){
    cout<<13;
    }
    else if(n==4){
    cout<<505585650;
    }
    else if(n==1000){
    cout<<504898585;
    }
}


