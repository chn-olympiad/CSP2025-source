#include <bits/stdc++.h>
using namespace std;
int a[12][12];
int b[105];
int n,m,l;
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>b[i];
    }
    int o=n*m;
    l=b[1];
    sort(b+1,b+o+1,cmp);
    int x=1,y=n+1,mp=1;
    for(int i=1;i<=m;i++){
        if(i%2==1){
            for(int j=x;j<y;j++){
                a[i][j]=b[mp];
                mp++;
            }
        }
        else{
            for(int j=y-1;j>=x;j--){
                a[i][j]=b[mp];
                mp++;
            }
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(a[i][j]==l){
                cout<<i<<" "<<j;
            }
        }
    }
    return 0;
}

