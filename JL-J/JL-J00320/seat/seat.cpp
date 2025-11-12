#include<bits/stdc++.h>
using namespace std;
int n,m,l=0,w;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=0;i<n*m;i++){
        if(i==0)cin>>w;
        else{
            int t;cin>>t;
            if(t>w)l++;
        }
    }
    cout<<l/n+1<<" "<<((l/n%2)?m-l%n:l%n+1);
}
