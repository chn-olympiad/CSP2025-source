#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int n,m,a[105],k,s,t;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[++t];
        }
    }
    k=a[1];
    sort(a+1,a+1+n*m);
    for(int i=n*m;i>=1;i--){
        if(a[i]==k){
            s=n*m-i+1;
            break;
        }
    }
    if(((s-1)/n+1)%2==1){
        cout<<((s-1)/n+1)<<" ";
        if(s%n==0){
            cout<<n;
        }else{
            cout<<s%n;
        }
    }else{
        cout<<((s-1)/n+1)<<" ";
        if(s%n==0){
            cout<<1;
        }else{
            cout<<n-s%n+1;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
