#include<bits/stdc++.h>
using namespace std;
struct node{
    int st,en,pri;
}v[1000005];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m,k;
    cin>>n>>m>>k;
    int ans=0;
    for(int i=1;i<=m;i++){
        cin>>v[i].st>>v[i].en>>v[i].pri;
        ans+=v[i].pri;
    }
    int x;
    for(int i=1;i<=k*(m+1);i++){
        cin>>x;
    }
    cout<<ans;
    return 0;
}
