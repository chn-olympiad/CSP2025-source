#include<bits/stdc++.h>
using namespace std;
int dis[15][15];
int a[225];
bool cmp(const int &x,const int &y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    int p=a[1];
    int cnt=0;
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=n;i++){
        if(i%2){
            for(int j=1;j<=m;j++){
                dis[i][j]=a[++cnt];
            }
        }
        else{
            for(int j=m;j>=1;j--){
                dis[i][j]=a[++cnt];
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(dis[i][j]==p){
                cout<<i<<" "<<j;
                return 0;
            }
        }
    }
    return 0;
}
