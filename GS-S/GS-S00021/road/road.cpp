#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int m,n,k;
    cin>>m>>n>>k;
    int fix[n][3]={},lol[k][3]={},city[m]={},cost=0;
    for(int i=0;i<n;i++){
        cin>>fix[i][0];
        cin>>fix[i][1];
        cin>>fix[i][2];
    }
    for(int i=0;i<k;i++){
        cin>>lol[i][0];
        cin>>lol[i][1];
        cin>>lol[i][2];
    }
    for(int i=0;i<n;i++){
        if(city[fix[i][1]-1]==0||city[fix[i][0]-1]==0){
            cost+=fix[i][2];
            city[fix[i][1]-1]=1;
            city[fix[i][0]-1]=1;
        }
    }
    cout<<cost;
    return 0;
}
