#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
    return a>b;
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;cin>>n>>m;
    int a[105];
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    int v=a[1],st,x,y;
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=n*m;i++){
        if(a[i]==v){
            st=i;
            break;
        }
    }
    if((st%n)==0)x=(st/n);
    else x=(st/n+1);
    if(x&1){
        if((st%n)>0)y=(st%n);
        else y=n;
    }
    else{
        if((st%n)>0)y=(n-st%n+1);
        else y=1;
    }
    cout<<x<<" "<<y;
    return 0;
}
