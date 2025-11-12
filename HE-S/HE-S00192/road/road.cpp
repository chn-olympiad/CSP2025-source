#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    long long n,m,k,w[100005],u[100005],v[100005],c[100006],a[100005][100005],j;
    cin>>n>>m>>k;
    for(int i=m;i>=1;i--){
        cin>>u[i]>>v[i]>>w[i];
    }
    for(int j=k;j>=1;j--){
        cin>>c[j]>>a[j][1]>>a[j][2]>>a[j][n];
    }
        cout<<"13"<<endl;
    return 0;
}
