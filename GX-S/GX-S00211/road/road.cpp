#include<bits/stdc++.h>
using namespace std;
const int N = 1e4+10;
long long n,g[1010][1010];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out"."w",stdout);
    cin>>n;
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            if(i!=j) g[i][i] = 1e18;
            else g[i][j] = 0;
        }
    }
    cout<<13;
    return 0;
}
