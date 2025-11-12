#include<bits/stdc++.h>
using namespace std;
int n,m,r,cnt=1;
int a;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    cin>>r;
    for(int i=2;i<=n*m;i++){
        cin>>a;
        if(a>r) cnt++;
    }
    cout<<(cnt-1)/n+1<<" "<<(((cnt-1)/n+1)%2==0?n-(cnt-1)%n:(cnt-1)%n+1);
    return 0;
}
