#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,cnt=1,a;
    cin>>n>>m;
    cin>>a;
    for(int i=1;i<n*m;i++){
        int _;
        cin>>_;
        if(_>a) cnt++;
    }
    int vis,vis2;
    if(cnt%n==0) vis=cnt/n;
    else vis=cnt/n+1;
    if(vis%2==0){
        if(cnt%n==0) vis2=1;
        else vis2=n-cnt%n+1;
    }else{
        if(cnt%n==0) vis2=n;
        else vis2=cnt%n;
    }
    cout<<vis<<' '<<vis2;
    return 0;
}
