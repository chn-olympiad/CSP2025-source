#include<bits/stdc++.h>
using namespace std;
int n,m,r,c,a[105];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
        cin>>a[i];
    int t=1;
    for(int i=2;i<=n*m;i++){
        if(a[i]>a[1])
            ++t;
    }
    if(t<=n){
        c=1;
        r=t;
        cout<<c<<" "<<r;
        return 0;
    }
    if(t%n==0)
        c=t/n;
    else
        c=t/n+1;
    if(c%2==0){
        int j=t%n;
        if(j==0)
            j=n;
        r=n+1-j;
    }
    else{
        r=t%n;
        if(r==0)
            r=n;
    }
    cout<<c<<" "<<r;
    return 0;
}