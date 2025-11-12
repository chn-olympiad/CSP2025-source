#include<bits/stdc++.h>
using namespace std;
int n,m,k,o[1000001];
int c[11],a[11][10001];
long long num;
vector<pair<int,int> e[10003]
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++){
        int x,y,z;
        cin>>x>>y>>z;
        num+=z;
        e[x].push_back(make_pair(y,z));
        e[y].push_back(make_pair(x,z));
    }
    for(int i=1;i<=k;i++){
        cin>>c[i];
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
        }
    }
    cout<<num<<endl;
}