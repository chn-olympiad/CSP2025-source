#include<bits/stdc++.h>
//#define int long long
using namespace std;
int n,m,k;
int u[1000005],v[1000005],w[1000005];
int sum;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        cin>>u[i]>>v[i]>>w[i];
        sum+=w[i];
    }
    cout<<sum;
    return 0;
}
