#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,a[110],cnt=0;
    cin>>n>>m;
    cin>>a[1];
    for(int i=2;i<=n*m;i++){
        cin>>a[i];
        if(a[i]>a[1]){
            cnt++;
        }
    }
    int c,r;
    c=cnt/n+1;
    int n1=n*2;
    r=cnt%n1+1;
    if(r<=n){
        cout<<c<<" "<<r;
    }
    else if(r>n){
        r=n1-r+1;
        cout<<c<<" "<<r;
    }
    return 0;
}
