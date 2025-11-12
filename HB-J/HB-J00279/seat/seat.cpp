#include<bits/stdc++.h>
using namespace std;
int a[100][100];
int b[100005];
int cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>b[i];
    }
    int t=b[1];
    int len=0;
    sort(b+1,b+1+n*m,cmp);
    for(int i=1;i<=m;i++){
        if(i%2!=0){
            for(int j=1;j<=n;j++){
                a[i][j]=b[++len];
            }
        }
        else{
            for(int j=n;j>0;j--){
                a[i][j]=b[++len];
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i][j]==t){
                cout<<i<<" "<<j;
                break;
            }
        }
    }
    return 0;
}
