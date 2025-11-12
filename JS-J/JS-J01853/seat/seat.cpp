#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,s=0;
    cin>>n>>m;
    int a[n*m+1];
    cin>>a[1];
    for(int i=2;i<=n*m;i++){
        cin>>a[i];
        if(a[i]>a[1])s++;
    }
    cout<<s/n+1<<" ";
    if(s/n%2)cout<<n-s%n;
    else cout<<s%n+1;
    return 0;
}
