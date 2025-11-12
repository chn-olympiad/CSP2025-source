#include<bits/stdc++.h>
using namespace std;
int a[101],n,m,b,c,d;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    b=a[1];
    sort(a+1,a+1+n*m);
    for(int i=1;i<=n*m;i++){
        if(a[i]==b){
            c=n*m-i+1;
        }
    }
    d=c/n;
    if(c%n==0){
        cout<<d<<' ';
    }else{
        d=d+1;
        cout<<d<<' ';
    }
    if(d%2==0){
        cout<<(n-c%n)+1;
    }else{
        if(c%n==0){
            cout<<n;
        }else{
            cout<<c%n;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
