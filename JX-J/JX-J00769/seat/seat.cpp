#include<bits/stdc++.h>
using namespace std;
int const N=1e6+10;
int a[N];
int b[N];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    int ans=a[1];
    sort(a+1,a+n*m+1);
    int f=n*m;
    for(int i=1;i<=n*m;i++){
        b[i]=a[f];
        f--;
    }
    for(int i=1;i<=n*m;i++){
        if(b[i]==ans){
            ans=i;
            break;
        }
    }
    int dy=ans/n,dx=ans%n;
    if(dx>0)dy++;
    if(dx==0&&dy%2==0){
        cout<<dy<<" "<<1;
        return 0;
    }
    if(dx==0&&dy%2==1){
        cout<<dy<<" "<<m;
        return 0;
    }
    if(dy%2==1){
        cout<<dy<<" "<<dx;
        return 0;
    }
    if(dy%2==0){
        cout<<dy<<" "<<m-dx+1;
        return 0;
    }
    return 0;
}
