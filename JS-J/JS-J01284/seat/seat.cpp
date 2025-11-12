#include<bits/stdc++.h>
using namespace std;
int n,m,a,t = 1,c;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    cin>>a;
    for(int i = 1;i<n*m;i++){
        int b;
        cin>>b;
        if(b>a)t++;
    }c = (t-1)/n+1;
    cout<<c<<' ';
    if(c%2 == 1)cout<<(t-1)%n+1;
    else cout<<n-(t-1)%n;
    return 0;
}
