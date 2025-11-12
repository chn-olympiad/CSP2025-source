#include<bits/stdc++.h>
using namespace std;
int a[1000005],n,k,m,f=0;
void dfs(int x,int y,int t){
        if(f)return;
        if(a[n*m-t+1]==k){
                cout<<x<<' '<<y;
                f=1;
                return;
        }
        if(y==n){
                if(x%2)dfs(x+1,y,t+1);
                dfs(x,y-1,t+1);
        }
        if(y==1){
                if(x%2)dfs(x,y+1,t+1);
                dfs(x+1,y,t+1);
        }
        if(x%2)return dfs(x,y+1,t+1);
        dfs(x,y-1,t+1);
}
int main(){
        freopen("seat.in",stdin);
        freopen("seat.out",stdout);
        cin>>n>>m;
        for(int i=1;i<=n*m;i++)cin>>a[i];
        k=a[1];
        sort(a+1,a+n*m+1);
        dfs(1,1,1);
        return 0;
}
