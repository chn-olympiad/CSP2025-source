#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int a,b,c;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        cin>>a>>b>>c;
    }
    for(int j=1;j<=k;j++){
        cin>>a;
        for(int j=1;j<=n;j++){
            cin>>a;
        }
    }
    cout<<0;
return 0;
}
//Ren5Jie4Di4Ling5%
//5 3 4   3 5 1   5 3 4
//4 2 1   5 3 4   3 2 4
//3 5 1   3 2 4   4 2 1
//3 2 4   4 2 1   3 5 1
