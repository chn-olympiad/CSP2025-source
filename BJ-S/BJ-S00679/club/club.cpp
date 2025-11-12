#include<bits/stdc++.h>
#define MAXN 100005
using namespace std;
int n,s,t;
int a[MAXN][4],c[4];
void dfs(int x,int y){
    if(x>n){
        s=max(s,y);
        return;
    }
    for(int i=1;i<4;i++){
        if(c[i]<n/2)c[i]++,dfs(x+1,y+a[x][i]),c[i]--;
    }
}
int main(){
    freopen("club.in","r",stdin),freopen("club.out","w",stdout),cin>>t;
    while(t--){
        s=0,cin>>n;
        for(int i=1;i<=n;i++)cin>>a[i][1]>>a[i][2]>>a[i][3];
        dfs(1,0),cout<<s<<endl;
    }
    return 0;
}