#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[13][13]={0};
int c[1003]={0};

bool sum(int a,int b){
    return b<a;
}
int main(){
    //freopen("seat.in","r",stdin);
    //freopen("seat.out","w",stdout);
    cin>>n>>m;
    int b=n*m;
    int d[m+1];
    for(int i=1;i<=b;++i){
        cin>>c[i];
    }

    int xm=c[1];
    sort(c+1,c+b+1,sum);

    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            a[i][j]=c[i];
        }

    }

    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            if(a[i][j]==xm){
                cout<<j<<" "<<i;
                break;
            }
        }

    }

    return 0;
}
