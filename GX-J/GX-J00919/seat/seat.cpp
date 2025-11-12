#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,cnt=1,A=0,c,r;
    cin>>n>>m;
    vector<int> a(n*m);
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
        if(a[1]<a[i]){
            cnt++;
        }
        if(a[i]!=i){
            A=1;
        }
    }
    if(A==0){
        if(m%2==0)
            cout<<m<<" "<<1;
        else
            cout<<m<<" "<<n;
        return 0;
    }
    if(n==1){
        cout<<1<<" "<<cnt;
        return 0;
    }
    if(m==1){
        cout<<cnt<<" "<<1;
        return 0;
    }
    if(m==1&&n==1){
        cout<<1<<" "<<1;
        return 0;
    }
    if(cnt==1){
        cout<<1<<" "<<1;
        return 0;
    }
    if(cnt%n==0){
        c=cnt/n;
        if(cnt/n%2==0)
            r=1;
        else
            r=n;
    }
    else{
        c=cnt/n+1;
        r=cnt%n;
        if(c%2==0)
            r=n-r+1;
    }
    cout<<c<<" "<<r;
    return 0;
}
