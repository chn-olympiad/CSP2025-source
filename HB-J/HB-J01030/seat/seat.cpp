#include<bits/stdc++.h>
using namespace std;
int n,m,p,q;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=0,u;i<n;i++)
        for(int j=0;j<m;j++){
            if(!i&&!j) cin>>p;
            else{
                cin>>u;
                if(u>p) q++;
            }
        }
    cout<<q/n+1<<' ';
    if((q/n+1)&1) cout<<q%n+1;
    else cout<<n-q%n;
}
