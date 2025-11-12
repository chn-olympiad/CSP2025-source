#include<bits/stdc++.h>
using namespace std;
int l[1000010][3];
int x[10010][1000000];
int main(){
    space('in',"road.in");
    space('out',"road.out");
    int n,m,k,aaa=0;
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        cin>>l[i][1];
        cin>>l[i][2];
        cin>>l[i][3];
        aaa+=l[i][2];
    }
    for(int i=1;i<=k;i++){
        cin>>x[i][1];
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
        }
    }
    cout<<aaa;
    return 0;
}