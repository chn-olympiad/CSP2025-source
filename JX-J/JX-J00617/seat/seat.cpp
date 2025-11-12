#include<bits/stdc++.h>
using namespace std;
int n,m,a[110],k;
int px(int a,int b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    int t=a[1];
    sort(a+1,a+n*m+1,px);
    for(int i=1;i<=n*m;i++){
        if(a[i]==t){
            k=i;
            break;
        }
    }
    cout<<(k-1)/n+1<<" ";
    if(((k-1)/n+1)%2==1){
        if(k%n==0){
            cout<<n;
        }
        else{
            cout<<k%n;
        }
    }
    else{
        if(k%n==0){
            cout<<1;
        }
        else{
            cout<<n-(k%n)+1;
        }
    }
    return 0;
}
