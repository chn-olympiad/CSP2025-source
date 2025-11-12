#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10;
const int M=1e6+10;
int d[N],f[N],c[M];
map<int,int> arr[N];
vector<int> vct[N];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k,sum=0;
    cin>>n>>m>>k;
    for(int i=0;i<n;i++){
        int u,v,w;
        cin>>u>>v>>w;
        sum+=w;
    }
    for(int i=0;i<m;i++){
        cin>>c[i];
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
    cout<<sum;
    return 0;
}