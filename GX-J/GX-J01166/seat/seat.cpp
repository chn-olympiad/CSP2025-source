#include<bits/stdc++.h>
using namespace std;
int n,m,a[105];
int f(int v){
    for(int i=n*m;i>0;i--){
        if(a[i]==v)return n*m-i+1;
    }
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    int sb=a[1];
    sort(a+1,a+(n*m)+1);
    int k=f(sb);
    int q=(k%n==0)?k/n:k/n+1;
    cout<<q<<" ";
    if(q%2==1){
        if(k%n==0)cout<<n;
        else cout<<k%n;
    }
    else{
        if(k%n==0)cout<<1;
        else cout<<n-k%n+1;
    }
    return 0;
}
