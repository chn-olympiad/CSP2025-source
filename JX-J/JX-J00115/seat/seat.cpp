#include<bits/stdc++.h>
using namespace std;
long long n,m,x,y,cnt=1,a,b;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m>>x;
    for(int i=1;i<n*m;i++){
        cin>>y;
        if(y>x)cnt++;
    }
    a=(cnt-1)/n+1;
    b=(cnt-1)%n+1;
    cout<<a<<" ";
    if(a%2==0)cout<<n-b+1;
    else cout<<b;
    return 0;
}
