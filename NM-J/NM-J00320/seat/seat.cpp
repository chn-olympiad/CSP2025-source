#include<bits/stdc++.h>
using namespace std;
int main() {
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int a[100],b;
    cin>>b;
    for(int i=1;i<=b;i++){
        cin>>a[i];
    }
    int n,m,c,r;
    cin>>n>>m;
    for(int i=1;i<=b;i++){
      if(n==1||m==1){
        c=1;
        r=1;
        cout<<c<<r;
    }
}
    return 0;
}
