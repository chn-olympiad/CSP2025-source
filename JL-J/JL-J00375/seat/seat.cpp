#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[n+10][m+10]={0},b[n*m]={0};
    for(int i=0;i<n*m;i++){
        cin>>b[i];
    }
    sort(b,b+n*m);
    int o=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++,o++)
            a[i][j]=b[o];
            o++;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            cout<<a[i][j]<<" ";
            cout<<endl;
    }
    return 0;
}
