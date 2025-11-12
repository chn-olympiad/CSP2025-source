#include<bits/stdc++.h>
using namespace std;
int n,m,x,sum;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    cin>>x;
    sum=1;
    for(int i=2;i<=n*m;i++){
        int a;
        cin>>a;
        if(a>x) sum++;
    }
    int c,r;
    c=(sum+n-1)/n;
    if(c%2==1) r=sum-c*n+n;
    else r=c*n-sum+1;
    cout<<c<<" "<<r;
    return 0;
}
