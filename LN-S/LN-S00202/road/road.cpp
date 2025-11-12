#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    cin>>n>>m>>k;
    vector<int> w;
    int cnt=0;
    for(int i=1;i<=n;i++){
            int u,v,k;
        cin>>u>>v>>k;
        cnt+=k;
    }
    cout<<cnt;
return 0;
}
