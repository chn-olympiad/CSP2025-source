#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,k,t,s,b,t1=0;
    cin>>n>>m;
    int a[n*m+10];
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    k=a[1];
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=n*m;i++){
        if(a[i]==k){
            t=i;
            break;
        }
    }
    if(t<=n){
        cout<<1<<" "<<n;
        return 0;
    }
    b=t;
    while(b-n>=0){
        b=b-n;
        t1++;
    }
    if(t1%2==0&&b==0){
        cout<<t1<<" "<<1;
        return 0;
    }
    if(t1%2==0&&b!=0){
        cout<<t1+1<<" "<<b;
        return 0;
    }
    if(t1%2!=0&&b==0){
        cout<<t1<<" "<<n;
        return 0;
    }
    if(t1%2!=0&&b!=0){
        cout<<t1+1<<" "<<n-b+1;
        return 0;
    }
    return 0;
}
