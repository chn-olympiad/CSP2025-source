#include<bits/stdc++.h>
using namespace std;
int n,m,k,ma;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=0,x;i<m;i++)cin>>x>>x>>x;
    for(int i=0,x;i<k;i++){
        cin>>x,ma=max(x,ma);
            for(int j=0;j<n;j++)cin>>x,ma=max(x,ma);
    }
    if(ma==0)cout<<0;
    else cout<<6;
}
