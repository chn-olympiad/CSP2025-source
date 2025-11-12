#include<bits/stdc++.h>
using namespace std;
int cnt;int n,m; char a[1001];int b[1001];int f;
void dfs(int t,int ren){
    if(t==n&&ren>=m){
        cnt++;
    }
    f=0;
    for(int i=0;i<n;i++){
        if(b[i]!=0)f = 1;
    }
    if(f==0)return;
    for(int i=0;i<n;i++){
        if(a[t]=='1'){
            dfs(t+1,ren+1);
        }
        else{
            for(int i=0;i<n;i++)b[i]--;
            dfs(t+1,ren);
            for(int i=0;i<n;i++)b[i]++;
        }
    }
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    dfs(0,0);
    cout<<cnt;
    return 0;
}
