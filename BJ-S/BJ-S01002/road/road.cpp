#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,b;
    cin>>n>>m>>b;
    int a[n][3],s[b][n+1];
    for(int i=0;i<n;i++){
        for(int j=0;j<3;j++){
            cin>>a[i][j];
        }
    }
    for(int i=0;i<b;i++){
        for(int j=0;j<n+1;j++){
            cin>>s[i][j];
        }
    }
    int nq=1000000;
    for(int i=0;i<b;i++){
            int h;
        for(int j=0;j<n+1;j++){
            h+=s[i][j];
        }
        if(h<nq)nq=h;
    }
    int y=100000;
    for(int i=0;i<n;i++){
        for(int j=0;j<2;j++){
            int hl=a[i][n]+a[i][n+1]+a[i+1][n]+a[i][n+1];
            int hl1=a[i][2]+a[i+1][2];
            if(hl>=(n+1)/2&&y>hl1)y=hl1;
        }
    }
    cout<<y+nq;
     return 0;
}
