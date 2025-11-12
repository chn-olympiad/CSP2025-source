#include<bits/stdc++.h>
using namespace std;
int a[1005];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,k,w=1;
    cin>>n>>m>>k;
    for(int i=2;i<=n*m;i++){
        int t;cin>>t;
        if(t>k)w++;
    }
    int x=0,y=1,d=1,jsq=0;
    for(int i=1;i<=w;i++){
        if(jsq<n){
            x+=d;
            jsq++;
        }else{
            d*=-1;
            y++;
            jsq=1;
        }
        //cout<<i<<":"<<x<<","<<y<<"\n";
    }
    cout<<y<<" "<<x;
    return 0;
}
