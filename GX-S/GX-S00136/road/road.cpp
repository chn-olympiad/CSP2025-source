#include<bits/stdc++.h>;
using namespace std;
vector<int> vec[1001];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;cin>>n>>m>>k;
    int sum=0;
    for(int i=1;i<=m;i++){
        int x,y,z;cin>>x>>y>>z;
        sum+=y;
    }
    cout<<sum;
    return 0;
}
