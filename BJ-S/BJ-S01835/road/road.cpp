#include<bits/stdc++.h>
using namespace std;
int u[1000001];
int v[1000001];
int w[1000001];
int a[1000001][1000001];
//int b[1000001];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    int sum = 0;
    int ltb = 0;
    cin>>n>>m>>k;
    for(int i = 1;i <= m;i++){
        cin>>u[i]>>v[i]>>w[i];
    }
    for(int i = 1;i <= k;i++){
        for(int j = 0;j < n;j++) cin>>a[i][j];

    }
    for(int j = 1;j <= k;j++){
        for(int i = 1;i <= m;i++){
            if(a[j][1]+a[j][u[i]]+a[j][v[i]] < w[i]){
                sum += a[j][1]+a[j][u[i]]+a[j][v[i]];
                a[j][1] = 1e9;
            }
            else{
                sum+=w[i];
            }

        }
    }
    cout<<sum;
        return 0;
}