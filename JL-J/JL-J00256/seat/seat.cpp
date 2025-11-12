#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,c=0,r=0,b=0,d=0;
    cin>>n>>m;
    int a[n*m];
    int o[4]={4,3,2,1};
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    d=a[1];
    sort(a[n*m],n*m);
    for(int i=1;i<=n*m;i++){
        if(a[i]==d){
            b=i;
            break;
        }
    }
    c=b/(n+1)+1;
    if(c%2==0){
        r=o[(b%n)-1];
    }else{
        r=b%n;
    }
    cout<<c<<r;
    return 0;
}

