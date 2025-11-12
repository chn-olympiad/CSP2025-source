#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[1000005]={0};
    int q;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
        q=a[1];
    }
    sort(a,a+n*m+1);
    for(int i=1;i<=n*m;i++){
        if(a[i]==q){
            q=m*n-i+1;
            break;
        }
    }
    int b;
    if(q%n==0){
        b=q/n;
    }else{
        b=q/n+1;
    }
    if(b%2==1){
        int c=q%m;
        if(c==0){
            cout<<b<<" "<<m;
        }else{
            cout<<b<<" "<<c;
        }
    }else{
        int c=q%m;
        if(c==0){
            c=1;
        }else{
            c=m-c+1;
        }
        cout<<b<<" "<<c;
    }
    return 0;
}
