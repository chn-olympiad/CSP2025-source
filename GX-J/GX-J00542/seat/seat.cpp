#include<bits/stdc++.h>
using namespace std;
int n,m,x;
int a[100][100],b[1000000];
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            for(int o=1;o<=n*m;o++){
                b[o]=a[i][j];
            }
        }
    }
    sort(b+1,b+1+b);
    for(int i=1;i<=n*m;i++){
            cout<<b[i];
        if(a[1][1]==b[i]){
            x=i;
        }
    }
    return 0;
}
