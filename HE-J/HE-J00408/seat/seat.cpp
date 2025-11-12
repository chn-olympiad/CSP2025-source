#include<bits/stdc++.h>
using namespace std;
int n,m,t,R,k=1;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    cin>>R;
    for (int i=1;i<n*m;i++){
        cin>>t;
        if (t>R)
            k++;
    }
    int c=(k-1)/n+1,r=(k-1)%n+1;
    if (c%2==1)
        cout<<c<<" "<<r;
    else
        cout<<c<<" "<<n+1-r;
    return 0;
}
