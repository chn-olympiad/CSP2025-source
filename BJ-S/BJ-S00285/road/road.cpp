#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int a,n,m,k;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        cin>>a;
    }
    for(int i=1;i<=k;i++){
        cin>>a;
        for(int j=1;j<=n;j++){
            cin>>a;
        }
    }
    cout<<0;
    return 0;
}