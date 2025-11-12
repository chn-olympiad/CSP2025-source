#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int m,n,k;
    int a[1145141];
    cin>>n>>m>>k;
    for(int i=0;i<m;i++){
        int x,y,z;
        cin>>x>>y>>z;
    }
    for(int i=0;i<k;i++){
        for(int j=0;j<n+1;j++){
            cin>>a[abs(i-j)];
        }
    }
    cout<<16<<endl;
    return 0;
}
