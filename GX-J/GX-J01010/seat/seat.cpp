#include<iostream>
#include<algorithm>
#include<stdio.h>
using namespace std;
int n,m;
int a[12][12],b[105],js=1,c;
bool px(int c,int d){
    return c>d;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
            b[js]=a[i][j];
            js++;
        }
    }
    c=b[1];
    sort(b+1,b+js,px);
    js=1;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            a[i][j]=b[js];
            js++;
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(a[i][j]==c){
                cout<<i<<" "<<j;
            }
        }
    }
    return 0;
}
