#include<bits/stdc++.h>
using namespace std;
int a[105];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;//n hang m lie
    cin>>n>>m;
    int cnt=1;
    for(int i=1;i<=n*m;i++) cin>>a[i];
    for(int i=2;i<=n*m;i++){
        if(a[i]>a[1]) cnt++;
    }
    int c=1,r=1;//c lie r hang
    if(cnt%n==0) c=cnt/n;
    else c=cnt/n+1;
    if(c%2==1){
        if(cnt%n==0) r=n;
        else r=cnt%n;
    }else{
        if(cnt%n==0) r=1;
        else r=n-cnt%n+1;
    }
    cout<<c<<" "<<r<<endl;
    return 0;
}
