#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("road.in", "r", stdin);
    freopen("road.ans", "w", stdout);
    int n,m,k,x[101000],y[101100],z[1010101],ans=0;
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        cin>>x[i]>>y[i]>>z[i];
    }
    for(int i=1;i<4;i++){
        for(int j=1;j<=4-i;j++){
            if(z[j]>z[j+1]){
                swap(z[j],z[j+1]);
            }
        }
    }
    for(int i=1;i<n;i++){
        ans=ans+z[i];
    }
    cout<<ans;
    return 0;
}
