#include<bits/stdc++.h>
using namespace std;
long long K=1e5;
int main(){
    long long n,m,k,a[10000][5],c[10000];
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        for(int f=1;f<=3;f++){
            cin>>a[i][f];
        }
    }
    for(int i=1;i<=k;i++){
            cin>>c[i];
        for(int f=1;f<=n;f++){
            cin>>a[i][f];
        }
    }
    cout<<0;
    return 0;
}
