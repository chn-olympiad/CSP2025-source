#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    int k;
    cin>>k;
    int cnt=1;
    for(int i=2;i<=n*m;i++){
        int ai;
        cin>>ai;
        if(ai>k) cnt++;
    }
    int c=0,r=0;
    if((cnt-1)/n%2==0){
        c=(cnt-1)/n+1;
        r=(cnt-1)%n+1;
    }else{
        c=(cnt-1)/n+1;
        r=n-(cnt-1)%n;
    }
    cout<<c<<" "<<r<<endl;
    return 0;
}
