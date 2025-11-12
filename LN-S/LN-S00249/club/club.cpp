#include <bits/stdc++.h>
using namespace std;
int a[4],n;
long long _max,c;
long long b[1000][4];
int nexts[4]={0,1,2,3};
int t;

void dfs(int x,int y){
    c+=b[x][y];
    if(x>=n){
        _max=max(_max,c);
        return;
    }
    for(int i=1;i<=3;i++){
        if(a[i]+1<=n/2){
            a[i]++;
            dfs(x+1,nexts[i]);
            a[i]--;
            c-=b[x+1][nexts[i]];
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;

    for(int x=0;x<t;x++){
        cin>>n;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=3;j++){
                cin>>b[i][j];

            }
        }
        a[1]=1;
        dfs(1,1);
        a[1]=0;
        c=0;
        a[2]=1;
        dfs(1,2);
        a[2]=0;
        a[3]=1;
        c=0;
        dfs(1,3);
        c=0;
        cout<<_max<<'\n';
        _max=0;
    }

    return 0;
}
