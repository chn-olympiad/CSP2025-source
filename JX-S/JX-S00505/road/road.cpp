#include<bits/stdc++.h>
using namespace std;
int a,b,c;
int x,y,z;
int const N=1e4+10;
int d[N][N];
int ans;
int main(){
    //freopen("road.in","r",stdin);
    //freopen("road.out","w",stdout);
    cin>>a>>b>>c;
    for(int i=1;i<=a;i++){
        cin>>x>>y>>z;
        ans+=min(y,z);
    }
    for(int i=1;i<=a+1;i++){
        for(int j=1;j<=a+1;j++){
            ans+=min(d[i][a],min(d[i][a-1],d[i][a+1]));
        }
    }
    cout<<ans;
}
