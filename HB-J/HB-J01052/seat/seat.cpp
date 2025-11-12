#include<bits/stdc++.h>
using namespace std;
int n,m,a[114514],a1,q;
int g[9191][9191];
int cpp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }a1=a[1];
    sort(a+1,a+n*m,cpp);

    int c=n*m;
    int n1=1,m1=1,f=0;
    while(c){
        if(f==0){
            g[n1][m1]=a[n*m-c+1];
            n1++;
            if(n1>n){
                m1++;
                f=1;
            }c--;
        }
        if(f==1){
            n1--;
            g[n1][m1]=a[n*m-c+1];
            if(n1==0){
                m1++;
                f=0;
            }c--;
        }
    }
    for(int i=1;i<=n;i++){
       for(int j=1;j<=m;j++){
            if(g[j][i]==a1){
                cout<<i<<' '<<j;
                return 0;
            }
        }
    }
    return 0;
}
