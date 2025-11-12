#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,g[105];
bool cmp(int x,int y){
    return x>y;
}
signed main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>g[i];
    }
    int k=g[1],pos=0;
    sort(g+1,g+n*m+1,cmp);
    for(int i=1;i<=m*n;i++){
        if(g[i]==k){
            pos=i;
        }
    }
    int x=ceil(pos*1.0/n),y=0;
    if(x%2==1){
        y=pos%n;
        if(y==0)y=n;
    }
    else{
        y=pos%n;
        if(y==0)y=n;
        y=n-y+1;
    }
    cout<<x<<" "<<y;
    return 0;
}
