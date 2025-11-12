#include<bits/stdc++.h>
using namespace std;
int a[105];
int seat[15][15];
bool cmp(int a,int b){
    if(a<b){
        return false;
    }
    else return true;
}
void dfs(int n,int m){
    int x=1;
    for(int i=1;i<=n;i++){
        if(i%2==0){
            for(int j=n;j>=1;j--){
                seat[i][j]=a[x];
                x++;
            }
        }
        else{
            for(int j=1;j<=m;j++){
                seat[i][j]=a[x];
                x++;
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    int t=a[1];
    sort(a+1,a+n*m+1,cmp);
    dfs(n,m);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(seat[i][j]==t){
                cout<<i<<" "<<j<<endl;
                return 0;
            }
        }
    }
}
