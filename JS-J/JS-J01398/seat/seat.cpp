#include<bits/stdc++.h>
using namespace std;
int n,m,p,a[105];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)cin>>a[i];
    for(int i=1;i<=n*m;i++)if(a[i]>=a[1])p++;
    if(((p-1)/n)&1)cout<<(p-1)/n+1<<" "<<n-(p-1)%n;
    else cout<<(p-1)/n+1<<" "<<(p-1)%n+1;
}
