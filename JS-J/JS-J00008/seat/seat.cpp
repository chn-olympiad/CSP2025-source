#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    vector<vector<int>> g(n,vector<int>(m));
    int v=0;
    int x=0,y=0;
    bool z=true;
    while(v<=n*m){
            v++;
        g[x][y]=v;

        if(z){
            x++;
            if(x>=n){
                x=n-1;
                y++;
                z=false;
            }
        }
        else{
            x--;
            if(x<0){
                x=0;
                y++;
                z=true;
            }
        }
    }
    //for(int i=0;i<n;i++){for(int j=0;j<m;j++)cout<<g[i][j]<<' ';cout<<endl;}
    vector<int> a(n*m);
    for(int i=0;i<n*m;i++){
        cin>>a[i];
    }
    int c=a[0];
    int p=0;
    sort(a.begin(),a.end(),greater<int>());
    for(int i=0;i<n*m;i++){
        if(a[i]==c){
            p=i+1;
            break;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(g[i][j]==p){
                cout<<j+1<<' '<<i+1;
                return 0;
            }
        }
    }
    return 0;
}
