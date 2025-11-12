#include<bits/stdc++.h>
using namespace std;
int a[105];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    int q=a[1];
    sort(a+1,a+m*n+1);
    int w=0;
    for(int i=1;i<=n*m;i++){
        if(a[i]==q){
            w=i;
        }

    }
    w=n*m-w+1;
    int c=0;
    if(w%n==0){
        c=w/n;
    }
    else{
        c=w/n+1;
    }
    int r=0;
    if(c%2==1){
        r=w-(c-1)*n;
    }
    else{
        r=n-w+(c-1)*n+1;
    }
    cout<<c<<" "<<r;
    return 0;
}

