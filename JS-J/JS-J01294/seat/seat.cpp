#include<bits/stdc++.h>
using namespace std;
int n,m,a[1005];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    int x,cnt=1;
    cin>>x;
    for(int i=1;i<n*m;i++){
        cin>>a[i];
        if(x<a[i]) cnt++;
    }
    int u=cnt/n,v=cnt%n;
    if(v!=0) u++;
    if(u%2==0) v=(n-v+1)%n;
    cout<<u<<' '<<v;
    return 0;
}
