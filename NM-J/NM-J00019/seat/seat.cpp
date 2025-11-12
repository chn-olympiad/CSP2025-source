#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int m,n,maxn=1;
    cin>>n>>m;
    int a,b;
    cin>>a;
    for(int i=2;i<=m*n;i++){
        cin>>b;
        if(b>a){
            maxn++;
        }
    }
    int i; 
    if(maxn/n*n==maxn){
        i=maxn/n;
    }else{
        i=maxn/n+1;
    }
    cout<<i<<' ';
    int j=maxn%n;
    if(j==0)j=n;
    if(i%2==0)  cout<<n-j+1;
    else cout<<j;
    return 0;
}
