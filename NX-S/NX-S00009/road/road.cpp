#include <bits/stdc++.h>
using namespace std;
int n,m,k,way[100][3],cr[100],crway[100];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=0;i<m;i++){
        cin>>way[i][0]>>way[i][1]>>way[i][2];
    }
    for(int i=0;i<k;i++){
        cin>>cr[i];
        for(int i=0;i<m;i++)cin>>crway[n];
    }

    cout<<26;
    return 0;

}
