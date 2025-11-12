#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int k;
    cin>>k;
    int ans=0;
    for(int i=1;i<n*m;i++){
        int a;
        cin>>a;
        if(a>k)ans++;
    }
    int x=ans/n+1;
    int y;
    if(x%2)y=ans%n+1;
    else y=n-ans%n;
    cout<<x<<' '<<y;
    return 0;
}
