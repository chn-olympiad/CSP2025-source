#include<bits/stdc++.h>
using namespace std;
int main(){
//#ifndef OFFLINE_JUDGE
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
//#else
//freopen("/home/noi/J/seat/seat3.in","r",stdin);
//freopen("/home/noi/J/seat/seat3.out","w",stdout);
//#endif // OFFLINE_JUDGE
    int n,m;
    cin>>n>>m;
    int a1,ai,rk=1;
    cin>>a1;
    for(int i=2;i<=n*m;i++){
        cin>>ai;
        if(ai>a1)rk++;
    }
    int c=rk/n+1,r=(rk%n);
    if(r==0){
        r=m;c-=1;
    }
    if(c%2==0)r=m+1-r;
    cout<<c<<' '<<r;
    return 0;
}

