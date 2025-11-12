#include<bits/stdc++.h>
using namespace std;
int n,m;
int c,r;
int a[105];
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    int k=a[1];
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=n*m;i++){
        if(a[i]==k){
            k=i;
            break;
        }
    }
    c=ceil(k*1.0/n);
    if(c%2==1){
        if(k%n==0)r=n;
        else r=k%n;
    }
    else {
        if(k%n==0)r=1;
        else r=n-k%n+1;
    }
    cout<<c<<" "<<r;
    return 0;
}
