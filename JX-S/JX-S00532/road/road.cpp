#include<bits/stdc++.h>
using namespace std;
int n,m,k,a[1005][1005],c[1005][1005],s=0;
int main(){
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=3;j++){
            cin>>a[i][j];
        }
    }
    for(int i=1;i<=k;i++){
        for(int j=0;j<=n;j++){
            cin>>c[i][j];
        }
    }
    for(int i=1;i<=n;i++){
           int l=INT_MAX;
           for(int j=0;j<=n;j++){
                if(c[i][j]<l){
                    l=c[i][j];
                }
           }
        s+=l;
    }
    cout<<s;
    return 0;
}
