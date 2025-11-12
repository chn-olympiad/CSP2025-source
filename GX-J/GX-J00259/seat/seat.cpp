#include<bits/stdc++.h>
using namespace std;
int n,m,k,l=1,q;
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    cin>>k;
    for(int i=2;i<=n*m;i++){
        cin>>q;
        if(q>k) l++;
    }
    int z=(l%n==0?l/n:l/n+1);
    cout<<z<<" "<<(z%2==0?(l%n==0?1:n-l%n+1):(l%n==0?n:l%n));
    return 0;
}
