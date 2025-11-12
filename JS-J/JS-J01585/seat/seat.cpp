#include<bits/stdc++.h>
using namespace std;
int a[102];
int n,m;
int tar;
inline void dfs(int x,int y,int cnt,bool d){
    if(a[cnt] == tar){
        cout<<x<<" "<<y;
        fclose(stdin);
        fclose(stdout);
        exit(0);
    }
    if(d == 1 && y+1 <= n) dfs(x,y+1,cnt+1,d);
    else if(d == 0 && y-1 >= 1) dfs(x,y-1,cnt+1,d);
    else {
        dfs(x+1,y,cnt+1,d^1);
    }
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    cin>>a[1];
    tar = a[1];
    for(int i=2;i<=n*m;i++) cin>>a[i];
    sort(a+1,a+n*m+1,greater<int>());
    dfs(1,1,1,1);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
