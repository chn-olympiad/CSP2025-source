#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a,b,cnt=1;
    cin>>a;
    for(int i=0;i<n*m-1;i++){
        cin>>b;
        if(b>a)cnt++;
    }
    cout<<(cnt-1)/n+1;
    if(((cnt-1)/n+1)%2==0)
    if(cnt%m==0)cout<<' '<<1;
    else cout<<' '<<n-cnt%n;
    else{
        if(cnt%m==0)cout<<' '<<m;
    else cout<<' '<<cnt%n;
    }
    return 0;
}
