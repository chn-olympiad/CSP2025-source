#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,m,sum,num=1;
    cin>>n>>m;
    cin>>sum;
    int s;
    while(cin>>s){
        if(s>sum) num++;
    }
    int r=(num-1)/n+1;
    int c=(num-1)%(2*n)+1;
    cout<<r<<" ";
    if(c<=n) cout<<c<<endl;
    else cout<<2*n+1-c<<endl;
    return 0;
}
