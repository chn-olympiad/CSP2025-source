#include<bits/stdc++.h>
using namespace std;
long long n,m,w,p;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m>>w;
    for(long long i=0;i<n*m-1;i++){
        long long x;
        cin>>x;
        if(x>w) p++;
    }
    cout<<p/n+1<<" ";
    if((p/n+1)%2) cout<<p%n+1;
    else cout<<n-(p%n+1)+1;
    return 0;
}
