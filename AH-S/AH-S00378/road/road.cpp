#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    int g=0,mx;
    for(int i=1;i<=m;i++){
        cin>>n>>k>>g;
        mx=max(mx,g);
    }
    cout<<mx;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
