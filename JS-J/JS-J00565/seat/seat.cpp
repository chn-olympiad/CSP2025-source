#include<bits/stdc++.h>
using namespace std;
int n,m,a[100];
int numm,k,c,r;
bool cmp(int z,int x){
    return z>x;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
        numm=a[1];
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=n*m;i++){
        if(a[i]==numm){
            k=i;
            break;
        }
    }
    if(k%n==0)c=k/n;
    else c=k/n+1;
    if(c%2==1){
        r=k%n;
        if(r==0)r=n;
    }else {
        if(k%n==0)
        r=n-k%n;
        else r=n-k%n+1;
    }cout<<c<<" "<<r;
    return 0;
}
