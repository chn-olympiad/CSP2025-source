#include<bits/stdc++.h>
using namespace std;
int n,m,a[500],s,si;
bool cmp(int t1,int t2){
    return (t1>t2);
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    s=a[1];
    sort(a+1,a+1+n*m,cmp);
    for(int i=1;i<=n*m;i++){
        if(s==a[i]){
            si=i;
        }
    }
    cout<<ceil(si*1.0/n)<<' ';
    if(int(ceil(si*1.0/n))%2==1){
        if(si%n!=0){
            cout<<si%n;
        }else{
            cout<<n;
        }
    }else{
        if(si%n!=0){
            cout<<n+1-si%n;
        }else{
            cout<<1;
        }
    }
    return 0;
}