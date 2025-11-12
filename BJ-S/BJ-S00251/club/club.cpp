#include<bits/stdc++.h>
using namespace std;
int a[10000][5];
int n;
int dfs(int i,int c,int x,int y,int z){
    if(!(i<=n)) return 0;
    int d=c;
    if(n/2>x){
        c=max(c,d+a[i][1]+dfs(i+1,d/*+a[i][1]*/,x+1,y,z));
    }if(n/2>y){
        c=max(c,d+a[i][2]+dfs(i+1,d/*+a[i][2]*/,x,y+1,z));
    }if(n/2>z){
        c=max(c,d+a[i][3]+dfs(i+1,d/*+a[i][3]*/,x,y,z+1));
    }
//    cout<<c<<' ';
    return c;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
    cin>>n;
    for(int i=1;i<=n;i++){
    cin>>a[i][1]>>a[i][2]>>a[i][3];
    }
    cout<<dfs(1,0,0,0,0)<<endl;
    }
    return 0;
}
